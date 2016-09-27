auto Matcher = functionDecl(allOf(
                   anyOf(hasAnyParameter(hasType(arrayType())),
                         hasAnyParameter(hasType(pointerType()))),
                   hasAnyParameter(hasType(asString("size_t"))))).bind("Function");
