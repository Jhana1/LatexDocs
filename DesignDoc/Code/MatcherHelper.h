namespace CAPA {

// Variable Binding Combinators
auto VarBind = [](std::string binding)
{
    return declRefExpr(to(varDecl().bind(binding)));
};

auto DVarBind = [](std::string binding)
{
    return hasDescendant(VarBind(binding));
};

auto VectorBind = [](std::string binding)
{
    return arraySubscriptExpr(
            hasBase(DVarBind(binding + "Base")),
            hasIndex(DVarBind(binding + "Index")));
};

auto MatrixBind = [](std::string binding)
{
    return arraySubscriptExpr(
            hasBase(hasDescendant(arraySubscriptExpr(
                hasBase(DVarBind(binding + "Base")),
                hasIndex(DVarBind(binding + "Row"))))),
            hasIndex(DVarBind(binding + "Column")));
};

// Loop Binding Combinators
auto LoopInit = [](std::string level)
{
    return anyOf(
        declStmt(hasSingleDecl(varDecl(hasInitializer(
            integerLiteral(anything()))).bind("InitVar" + level))),
        binaryOperator(
            hasOperatorName("="),
            hasLHS(VarBind("InitVar" + level))));
};

auto LoopIncrement = [](std::string level) 
{
    return anyOf(
            unaryOperator(anyOf(
                    hasOperatorName("++"),
                    hasOperatorName("--")),
                hasUnaryOperand(VarBind("IncVar" + level))),
            binaryOperator(anyOf(
                    hasOperatorName("+="),
                    hasOperatorName("-=")),
                hasLHS(VarBind("IncVar" + level)),
                hasRHS(expr().bind("Stride" + level))));
};

auto ForLoop = [](std::string binding, std::string level, auto injectBody)
{
    return forStmt(
            hasLoopInit(LoopInit(level)),
            hasCondition(binaryOperator(hasRHS(expr().bind(binding + "CondRHS")))),
            hasIncrement(LoopIncrement(level)),
            hasBody(injectBody)).bind(binding);
};

} // End Namespace CAPA
