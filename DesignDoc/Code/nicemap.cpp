auto left = VectorBind("Out");
auto right = hasDescendant(VectorBind("In"));
auto unless = hasDescendant(arraySubscriptExpr(hasDescendant(binaryOperator())));

auto body = hasDescendant(BinaryOperatorBindUnless("=", "Assign", left, right, unless)); 

auto MapMatcher = ForLoop("Map", "", body); 

addMatcher(MapMatcher);




