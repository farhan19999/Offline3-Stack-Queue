#include "Stack.cpp"

bool checkValidity(string s)
{
    int p = 0;
    for(int i = 0; i<s.length() ; i++)
    {
        if(s[i] == ' ')continue;
        if(s[i] == '(')++p;
        if(s[i] == ')')--p;
        if(p<0)return false;

        //Have to check for proper parenthesis of negative number
        if(s[i] == '-' && s[i-1] == '(')
        {
            int t = i+1;
            while(((s[t]>='0' && s[t]<='9') || s[t] == '.' || s[t] == ' ') && t<s.length() )t++;
            if(s[t] != ')' || t==s.length())return false;
        }

        //have to check proper use of operators
        if((s[i-1] == '+' || s[i-1] == '-' || s[i-1] == '*' || s[i-1] == '/') && i>0)
        {
            if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == ')')
            {
                return false;
            }
        }
    }
    if(p)return false;
    return true;
}

int main()
{
    string exp;
    getline(cin,exp);


    if(!checkValidity(exp))
    {
        cout<<"Not Valid"<<endl;
        return 0;
    }

    Stack<char>op;
    Stack<double> num;

    //wrapping the expression in a ()
    exp = "(" + exp + ")";


    for(int i = 0; i<exp.length() ; i++)
    {

        //parsing digit and converting to double
        if((exp[i]>= '0' && exp[i]<= '9') || exp[i] == '.'  )
        {
            string dig;
            int float_flag = 0;
            while(((exp[i]>='0' && exp[i]<='9') || exp[i] == '.') && i<exp.length() )
            {
                if(exp[i] == '.')
                {
                    if(float_flag)
                    {
                        cout<<"Not Valid"<<endl;
                        return 0;
                    }
                    else float_flag = 1;
                }
                dig.push_back(exp[i]);
                i++;
            }
            num.push(atof(dig.c_str()));

        }

        //handling operator and parenthesis
        if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '(')
        {
            //making '(-x)' into '(0-x)'
            if(exp[i] == '-' && exp[i-1] == '(')
            {
                num.push(0);
            }
            op.push(exp[i]);
        }

        //calculating inside of  a bracket
        if(exp[i] == ')')
        {
            char oper = op.top();
            op.pop();

            if(oper == '(')continue;

            double left;
            double right = num.top();
            num.pop();

            Stack<double>temp_num;
            Stack<char>temp_op;

            //First complete only division inside the bracket
            while(oper != '(' )
            {
                left = num.top();
                num.pop();

                if(oper == '/')
                {
                    if(right == 0)
                    {
                        cout<<"Invalid"<<endl;
                        return 0;
                    }
                    //cout<<left<<" "<<oper<<" "<<right<<" = "<<left/right<<endl;
                    right = left/right;
                }

                else if(oper == '+' || oper == '-' || oper == '*')
                {
                    temp_num.push(right);
                    temp_op.push(oper);
                    right = left;
                }

                oper = op.top();
                op.pop();

            }

            (temp_num.isEmpty()) ? num.push(right) : temp_num.push(right);

            if(temp_num.isEmpty())continue;
            Stack<double>final_num;
            Stack<char>final_op;
            left = temp_num.top();
            temp_num.pop();

            //completing only multiplication
            while(temp_op.getSize()>0)
            {

                oper = temp_op.top();
                temp_op.pop();

                right = temp_num.top();
                temp_num.pop();

                if(oper == '+' || oper == '-')
                {
                    final_num.push(left);
                    final_op.push(oper);
                    left = right;
                }

                else
                {
                    //cout<<left<<" "<<oper<<" "<<right<<" = "<<left*right<<endl;
                    left = left*right;
                }

            }

            (final_num.isEmpty()) ? num.push(left) : final_num.push(left);

            if(final_num.isEmpty())continue;

            //Finally finishing addition and substraction
            while(!final_op.isEmpty())
            {
                right = final_num.top();
                final_num.pop();


                left =  final_num.top();
                final_num.pop();

                oper = final_op.top();
                final_op.pop();

                if(final_op.top() == '-')right = -right;             // a-b+c = a-(b+(-c))

                if(oper == '+')
                {
                    //cout<<left<<" "<<oper<<" "<<right<<" = "<<left+right<<endl;
                    final_num.push(left+right);
                }

                else if(oper == '-')
                {
                    //cout<<left<<" "<<oper<<" "<<right<<" = "<<left-right<<endl;
                    final_num.push(left-right);
                }
            }

            if(!final_num.isEmpty())
            {
                num.push(final_num.top());
                final_num.pop();
            }
        }
    }


    cout<<"valid expression, Computed value: "<<num.top()<<endl;
    return 0;
}
