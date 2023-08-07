#include <iostream>
#include <string>

using namespace std;

int main() {
    string logo = R"(
 $$$$$$\                                                           $$$$$$\  $$\           $$\                           
$$  __$$\                                                         $$  __$$\ \__|          $$ |                          
$$ /  \__| $$$$$$\   $$$$$$\   $$$$$$$\  $$$$$$\   $$$$$$\        $$ /  \__|$$\  $$$$$$\  $$$$$$$\   $$$$$$\   $$$$$$\  
$$ |       \____$$\ $$  __$$\ $$  _____| \____$$\ $$  __$$\       $$ |      $$ |$$  __$$\ $$  __$$\ $$  __$$\ $$  __$$\ 
$$ |       $$$$$$$ |$$$$$$$$ |\$$$$$$\   $$$$$$$ |$$ |  \__|      $$ |      $$ |$$ /  $$ |$$ |  $$ |$$$$$$$$ |$$ |  \__|
$$ |  $$\ $$  __$$ |$$   ____| \____$$\ $$  __$$ |$$ |            $$ |  $$\ $$ |$$ |  $$ |$$ |  $$ |$$   ____|$$ |      
\$$$$$$  |\$$$$$$$ |\$$$$$$$\ $$$$$$$  |\$$$$$$$ |$$ |            \$$$$$$  |$$ |$$$$$$$  |$$ |  $$ |\$$$$$$$\ $$ |      
 \______/  \_______| \_______|\_______/  \_______|\__|             \______/ \__|$$  ____/ \__|  \__| \_______|\__|      
                                                                                $$ |                                    
                                                                                $$ |                                    
                                                                                \__|                                    
)";
    cout << logo;
    int choice = 0, shift;
    string message;
    while (choice != -1) {
        cout << "Type 1 for encrypt and 2 for decrypt and -1 to stop: ";
        cin >> choice;
        cin.ignore();
        if (choice == 1) {
            cout << "Type a message: ";
            getline(cin, message);
            cout << "Enter shift number: ";
            cin >> shift;
            for (int i = 0; i < message.length(); i++) {
                if (isalpha(message[i])) {
                    char base = isupper(message[i]) ? 'A' : 'a';
                    message[i] = static_cast<char>((message[i] - base + shift) % 26 + base);
                }
            }
            cout << "The encrypted message is: " << message << endl;
        } else if (choice == 2) {
            cout << "Type a message: ";
            getline(cin, message);
            cout << "Enter shift number: ";
            cin >> shift;
            for (int i = 0; i < message.length(); i++) {
                if (isalpha(message[i])) {
                    char base = isupper(message[i]) ? 'A' : 'a';
                    message[i] = static_cast<char>((message[i] - base - shift + 26) % 26 + base);
                }
            }
            cout << "The decrypted message is: " << message << endl;
        }
    }
    return 0;
}