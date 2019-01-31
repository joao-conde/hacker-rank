#include <bits/stdc++.h>

using namespace std;

class HRMLElement {
   private:
   public:
    string HRMLId;
    unordered_map<string, string> attributes;
    unordered_map<string, HRMLElement*> children;

    HRMLElement(){};

    HRMLElement(string id) { HRMLId = id; };

    void addAttribute(string attr, string val) {
        attributes.insert({attr, val});
    }

    void addChild(string childID, HRMLElement* child) {
        children.insert({childID, child});
    }

    friend ostream& operator<<(ostream& out, const HRMLElement& el) {
        out << el.HRMLId << " has:\n";
        for (auto p : el.attributes) {
            out << p.first << " - " << p.second << endl;
        }

        for (auto c : el.children) {
            out << "\tChild: ";
            out << c.first << "\n";
        }

        cout << "\nEnd of node " << el.HRMLId << endl;
        return out;
    }
};

bool isClosingTag(string line) { return (line[0] == '<' && line[1] == '/'); }

vector<string> readLines(int numLines) {
    vector<string> lines;
    string line;
    for (int i = 0; i < numLines; i++) {
        getline(cin, line);
        lines.push_back(line);
    }
    return lines;
}

HRMLElement* parseHRMLOpenTag(string line) {
    char dummy;
    string label, label2;
    line.erase(0, 1);                // remove '<'
    line.erase(line.size() - 1, 1);  // remove '>'

    stringstream ss(line);
    ss >> label;

    HRMLElement* el = new HRMLElement(label);
    while (!ss.eof()) {
        ss >> label >> dummy >> label2;
        el->addAttribute(label, label2);
    }

    return el;
}

HRMLElement* buildHRMLTree(vector<string>& lines) {
    HRMLElement* root = parseHRMLOpenTag(lines[0]);
    lines.erase(lines.begin() + 0);

    while (!isClosingTag(lines[0])) {
        HRMLElement* child = buildHRMLTree(lines);
        root->addChild(child->HRMLId, child);
    }

    lines.erase(lines.begin() + 0);

    return root;
}

int findNextOp(const string& query){
    unsigned int dotPos = query.find('.'), tilPos = query.find('~');
    if(dotPos == string::npos && tilPos == string::npos) return -1;
    return (dotPos < tilPos ? dotPos : tilPos);
}

pair<string, char> getNextToken(string& query) {
    char op = query[0];
    string label;
    query.erase(query.begin() + 0);

    int endPos = findNextOp(query);
    if(endPos == -1) endPos = query.size();

    label = query.substr(0, endPos);
    query.erase(query.begin(), query.begin() + endPos);

    return {label, op};
}

void processQuery(string query, HRMLElement* rootTag) {
    //remove 'tag1'
    int endPos = findNextOp(query);
    query.erase(query.begin(), query.begin() + endPos);

    while (!query.empty()) {
        pair<string, char> res = getNextToken(query);
        if(res.second == '.'){
            rootTag = rootTag->children[res.first];
        }
        else if(res.second == '~'){
            if(rootTag->attributes.find(res.first) != rootTag->attributes.end()){
                string sol = rootTag->attributes[res.first];
                sol.erase(0, 1);
                sol.erase(sol.size() - 1, 1);
                cout << sol << endl;
            }
            else
                cout << "Not Found!" << endl;

            break;
        }
    }
}

int main() {
    int numLines, numQueries;
    cin >> numLines >> numQueries;
    cin.ignore();

    vector<string> lines = readLines(numLines);
    HRMLElement* root = buildHRMLTree(lines);
    for (int i = 0; i < numQueries; i++) {
        string query;
        getline(cin, query);
        processQuery(query, root);
    }
}