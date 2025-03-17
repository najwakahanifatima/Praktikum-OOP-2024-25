#include "Expression.hpp"

class AddExpression : public BinaryExpression {
    public:
        AddExpression(Expression* x, Expression* y) : BinaryExpression(x,y){}
        int solve(){
            int result = x->solve() + y->solve();
            cout << result << endl;
            return result;
        }
};