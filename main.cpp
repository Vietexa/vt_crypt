
#include <cstdio>
#include <cstdlib>
#include <ios>
#include <iostream>
#include <sstream>
#include <fstream>
#include <filesystem>
#include <string>


std::string encrypt_characters(std::string text, std::string key) {

std::string encrypted_characters = "";

for (int i = 0; i < text.length(); i++) {
 encrypted_characters += text[i] ^ key[i % key.length()];
}

return encrypted_characters;

}

void create_note() {

std::string chosen_key = "";

std::cout << "Enter a 5-8 characters key that is going to be used to encrypt your text.\n";
std::getline(std::cin,  chosen_key);

if (chosen_key.length() < 5 || chosen_key.length() > 9 ) {
std::cout << "error: The length of the key is invalid\n";
return;
}

else{
std::cout << "Great! You have successfully chosen the key!\nPlease choose a name for your new file:";

std::string file_name = "";
std::string c_file_name = "";

std::getline(std::cin,file_name);

c_file_name = file_name + ".bin";

 if (std::filesystem::exists(c_file_name)) {
std::cout << "Error: That file already exists!\n";
return;
}

 else{

 std::ofstream new_file(c_file_name, std::ios::binary);
 std::cout << "success! " + c_file_name + " has been created\n";
 std::cout << "Now you can write whatever you want to be encrypted, use /stop when you are done using the program\n";

std::string text = "";
std::string encrypted_user_input = "";

 while (true) {

 std::string user_input;
 

 std::getline(std::cin, user_input);
 
if (user_input == "/stop"){
std::cout << "/stop has been triggered\n";
break;
}
else {
user_input += '\n';
text += user_input;
}

}

encrypted_user_input = encrypt_characters(text,chosen_key);

new_file.write((encrypted_user_input.c_str()), encrypted_user_input.size());


}

}

}

void read_note() {

std::string fl_name;
std::string entered_key;

bool send_back = true;


std::cout << "Enter name (without the extension) of the file you want to decrypt:\nIf you don't know the name use /files to list the files you have in your current directory.\n";



while (send_back == true) {
std::getline(std::cin, fl_name);
if (fl_name == "/files") {
system(R"(find . -name "*.bin")");
}

else{
 send_back = false;
}

}

fl_name += ".bin";

if (std::filesystem::exists(fl_name))
{
std::cout << "Enter the decryption key of the file:\n";
std::getline(std::cin, entered_key);

 if (entered_key.length() < 5 || entered_key.length() > 9) {
std::cout << "error: The length of the key is invalid\n";
return;
}

 else {

std::ifstream read_file(fl_name);

std::string extracted_data;
std::string decrypted_data;
std::stringstream s;

s << read_file.rdbuf();

extracted_data = s.str();

decrypted_data = encrypt_characters(extracted_data, entered_key);

std::cout << "This is the result of the decryption\n" + decrypted_data;



}


}
else{

std::cout << "Error: That file doesn't exist!\n";
return;
}





}



int main() {
std::string mode = "";

std::cout << "What would you like to do?\n1.Create a private note\n2.Read a private note\n";

std::getline(std::cin, mode);

if (mode == "1") create_note();
else if(mode == "2") read_note();

else{
std::cout << "The option you entered is not valid\n";
return 1; 
}


return 0;




    
}