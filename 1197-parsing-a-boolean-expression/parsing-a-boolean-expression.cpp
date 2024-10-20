class Solution {
public:
    int i = 0;
    string str;
    bool helper(){
        char c= str[i];
        i += 1;
        if (c == 't') return true;
        if (c == 'f') return false;
        i += 1;
        if (c == '!'){
            bool res = ! helper();
            i += 1;
            return res;
        }
        vector<bool> container;
        while (str[i] != ')'){
            if (str[i] != ',') container.push_back(helper());
            else i += 1;
        }
        i += 1;
        bool result = container[0];
        if (c == '&'){
            for (int ii = 1; ii < container.size(); ii++) result &= container[ii];
        }
        if (c == '|'){
            for (int ii = 1; ii < container.size(); ii++) result |= container[ii];
        }

        return result;
    }
    bool parseBoolExpr(string expression) {
        str = expression;
        return helper();
    }
};