auto left = VectorBind("Out");
auto right = forEachDescendant(VectorBindScan("In"));
auto body = anyOf(HasDescendant(BinaryOperatorBind("=", "Assign", left, right)),
                  HasDescendant(BinaryOperatorBindAll("Assign",  left, right))); 

auto ScanMatcher = FunctionWrap(ForLoopNoParentLoop("Scan", "", body));
