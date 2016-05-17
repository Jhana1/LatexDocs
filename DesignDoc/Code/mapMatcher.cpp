auto MapMatcher =
forStmt(
    hasLoopInit(anyOf(
        declStmt(hasSingleDecl(varDecl(hasInitializer(
            integerLiteral(anything()))).bind("InitVar"))),
        binaryOperator(
            hasOperatorName("="),
            hasLHS(declRefExpr(to(varDecl(hasType(
                isInteger())).bind("InitVar"))))))),
    hasCondition(binaryOperator(hasRHS(hasDescendant(
        declRefExpr().bind("var"))))),
    hasIncrement(unaryOperator(
        hasOperatorName("++"),
        hasUnaryOperand(declRefExpr(to(varDecl(hasType(isInteger()))
            .bind("IncVar")))))),
    hasBody(hasDescendant(binaryOperator(
        hasOperatorName("="),
        hasLHS(arraySubscriptExpr(
            hasBase(implicitCastExpr(hasSourceExpression(declRefExpr(to(
                varDecl().bind("OutBase")))))),
            hasIndex(hasDescendant(declRefExpr(to(varDecl(hasType(
                isInteger())).bind("OutIndex"))))))),
        hasRHS(hasDescendant(arraySubscriptExpr(hasBase(implicitCastExpr(
                hasSourceExpression(declRefExpr(to(varDecl().bind("InBase")))))),
                    hasIndex(hasDescendant(declRefExpr(to(varDecl(hasType(
                        isInteger())).bind("InIndex")))))))),
        unless(hasDescendant(arraySubscriptExpr(hasDescendant(binaryOperator())))))
        .bind("Assign")))).bind("Map");


addMatcher(MapMatcher);
