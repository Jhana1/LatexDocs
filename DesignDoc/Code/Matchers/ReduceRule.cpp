auto left = VarBind("Acc");
auto right1 = HasDescendant(VectorBind("In"));
auto right2 = allOf(DVarBind("AccRHS"), HasDescendant(VectorBind("In")));

auto body = anyOf(HasDescendant(BinaryOperatorBindReduceAll("Assign", left, right1)),
                  HasDescendant(BinaryOperatorBindReduce("Assign", left, right2)));

auto ForStmtReduceMatcher = FunctionWrap(ForLoop("Reduce", "", body));
auto WhileStmtReduceMatcher = FunctionWrap(WhileLoop("Reduce", "", body));
