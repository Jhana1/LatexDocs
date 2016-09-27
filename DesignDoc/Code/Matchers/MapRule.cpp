// Matches on For Loops with counter initialised in the init, with an array element
// assignment within the body of the loop
auto left = VectorBind("Out");
auto right = HasDescendant(VectorBind("In"));
auto unless = HasDescendant(arraySubscriptExpr(HasDescendant(binaryOperator())));

auto body = HasDescendant(BinaryOperatorBindUnless("=", "Assign", left, right, unless)); 
auto body2 = HasDescendant(BinaryOperatorBindAll("Assign", left, NumericLiteralBind("Literal")));

auto ForMatcher = FunctionWrap(ForLoop("Map", "", anyOf(body, body2))); 

auto WhileMatcher = FunctionWrap(WhileLoop("Map", "", body));
