#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Message {

    int id;
    string text;

    public: 
        Message(){}

        Message(int _id, string _text){
            id = _id;
            text = _text;
        }

        const int& get_id(){
            return id;
        }

        const string& get_text() {
            return text;    
        }

        bool operator<(Message &m){
            return (id < m.get_id());
        }
};

class MessageFactory {
    int curID;
    public:
        MessageFactory() {
            curID = 1;
        }
        Message create_message(const string& text) {
            return Message(curID++, text); 
        }
};


class Recipient {
    public:
        Recipient() {}
        void receive(const Message& msg) {
            messages_.push_back(msg);
        }
        void print_messages() {
            fix_order();
            for (auto& msg : messages_) {
                cout << msg.get_text() << endl;
            }
            messages_.clear();
        }
    private:
        void fix_order() {
            sort(messages_.begin(), messages_.end());
        }
        vector<Message> messages_;
};

class Network {
    public:
        static void send_messages(vector<Message> messages, Recipient& recipient) {
        // simulates the unpredictable network, where sent messages might arrive in unspecified order
            random_shuffle(messages.begin(), messages.end());         
            for (auto msg : messages) {
                recipient.receive(msg);
            }
        }
};

int main() {
    MessageFactory message_factory;
    Recipient recipient;
    vector<Message> messages;
    string text;
    while (getline(cin, text)) {
        messages.push_back(message_factory.create_message(text));
    }
    Network::send_messages(messages, recipient);
    recipient.print_messages();
}
