bool isValidParenthesis(string expression)
{
    stack<char> s;
    for(auto c : expression){
        if(c == '(' || c == '{' || c == '[') s.push(c);
        else{
          if (c == ')') {
            if (s.empty() || s.top() != '(')
              return false;
            else
              s.pop();
          } else if (c == '}') {
            if (s.empty() || s.top() != '{')
              return false;
            else
              s.pop();
          } else if(c == ']'){
            if(s.empty() || s.top() != '[') 
              return false;
            else 
              s.pop();
            }
        }
    }
    return s.empty();
}
