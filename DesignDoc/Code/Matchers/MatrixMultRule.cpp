auto LoopBody = 
    HasDescendant(
        binaryOperator(
            hasOperatorName("+="),
            hasLHS(MatrixBind("Out")),
            hasRHS(binaryOperator(
                hasOperatorName("*"),
                hasLHS(HasDescendant(MatrixBind("Left"))),
                hasRHS(HasDescendant(MatrixBind("Right"))))
    )));

auto MatrixMultMatcher = 
    FunctionWrap(
        ForLoop("MatrixMult", "0", HasDescendant(
            ForLoop("", "1",HasDescendant(
                ForLoop("", "2", LoopBody))))));
