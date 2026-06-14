class Solution {
public:
    bool isValid(string s) {
        stack<char> c;
        for (char i : s){
            if (i == '(' || i=='[' || i == '{'){
                c.push(i);
            }
            else if ((i == ')' || i==']' || i == '}') && c.empty()){
                return false;
            }
            else {
                if ((i==')' && c.top()!= '(' ) ||
                (i==']' && c.top()!= '[' ) ||
                (i=='}' && c.top()!= '{' )
                ) return false;
                c.pop();
            }
        }
        if (c.empty())
            return true;
        return false;
    }
};
