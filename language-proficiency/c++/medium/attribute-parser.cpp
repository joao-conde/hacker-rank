#include <bits/stdc++.h>

using namespace std;

class HRMLElement {
   public:
    string HRMLId;
    HRMLElement* parent = nullptr;
    unordered_map<string, string> attributes;
    unordered_map<string, HRMLElement*> children;

    void addAttribute(string attr, string val) {
        attributes.insert({attr, val});
    }

    void addChild(string childID, HRMLElement* child) {
        children.insert({childID, child});
    }
};

vector<string> readLines(int numLines) {
    vector<string> lines;
    string line;
    for (int i = 0; i < numLines; i++) {
        getline(cin, line);
        lines.push_back(line);
    }
    return lines;
}

bool isClosingTag(string line) { return (line[0] == '<' && line[1] == '/'); }

HRMLElement* parseOpenTag(string openTag) {
    HRMLElement* el = new HRMLElement();

    // remove '<' and '>'
    openTag.erase(openTag.begin());
    openTag.erase(openTag.begin() + openTag.size() - 1);

    char dummy;
    string attr, val;
    stringstream ss(openTag);

    ss >> el->HRMLId;  // elementID

    while (!ss.eof()) {
        ss >> attr >> dummy >> val;
        // remove "" from value
        val.erase(val.begin());
        val.erase(val.begin() + val.size() - 1);
        el->addAttribute(attr, val);
    }

    return el;
}

unordered_map<string, HRMLElement*> parseHRMLTree(const vector<string>& lines) {
    unordered_map<string, HRMLElement*> document;
    HRMLElement* cur = nullptr;
    for (string line : lines) {
        if (!isClosingTag(line)) {
            HRMLElement* el = parseOpenTag(line);
            if (cur != nullptr) {
                cur->addChild(el->HRMLId, el);
                el->parent = cur;
                cur = el;
            } else {
                document.insert({el->HRMLId, el});
                cur = el;
            }
        } else {
            cur = cur->parent;
        }
    }
    return document;
}

void answerQueries(unordered_map<string, HRMLElement*>& document,
                   int numQueries) {
    for (int i = 0; i < numQueries; i++) {
        string query;
        cin >> query;

        size_t firstTagPos = query.find('.');
        if (firstTagPos == string::npos) firstTagPos = query.find('~');

        HRMLElement* cur;
        auto it = document.find(query.substr(0, firstTagPos));
        if (it != document.end())
            cur = it->second;
        else {
            cout << "Not Found!" << endl;
            continue;
        }
        query.erase(query.begin(), query.begin() + firstTagPos);

        while (!query.empty()) {
            char op = query[0];
            query.erase(query.begin());

            if (op == '.') {
                size_t pos = query.find('.');
                if (pos == string::npos) pos = query.find('~');
                if (pos == string::npos) pos = query.size() - 1;
                string label = query.substr(0, pos);
                query.erase(query.begin(), query.begin() + pos);

                auto it = cur->children.find(label);
                if (it != cur->children.end())
                    cur = cur->children[label];  // dot operator
                else {
                    cout << "Not Found!" << endl;
                    break;
                }
            }

            if (op == '~') {
                auto it = cur->attributes.find(query);
                if (it != cur->attributes.end())
                    cout << it->second << endl;
                else
                    cout << "Not Found!" << endl;

                break;
            }
        }
    }
}

int main() {
    int numLines, numQueries;
    cin >> numLines >> numQueries;
    cin.ignore();

    vector<string> lines = readLines(numLines);
    unordered_map<string, HRMLElement*> document = parseHRMLTree(lines);

    answerQueries(document, numQueries);
}