auto unless = anyOf(
                HasDescendant(ifStmt(anything())),
                HasDescendant(switchStmt(anything())),
                HasDescendant(gotoStmt(anything())),
                hasAncestor(forStmt(anyOf(
                    hasAncestor(forStmt(anything())),
                    hasAncestor(whileStmt()),
                    hasAncestor(doStmt())))),
                hasAncestor(whileStmt(anyOf(
                    hasAncestor(forStmt(anything())),
                    hasAncestor(whileStmt(anything())),
                    hasAncestor(doStmt(anything()))))),
                hasAncestor(doStmt(anyOf(
                    hasAncestor(forStmt(anything())),
                    hasAncestor(whileStmt()),
                    hasAncestor(doStmt()))))
                );

auto body = anything();

auto ForMatcher = FunctionWrap(ForLoopUnless("Loop", body, unless));
auto WhileMatcher = FunctionWrap(WhileLoopUnless("Loop", body, unless));
