bool markedIgnore(const Decl *d, SourceManager &sm)
{
    if (!d) { return false; }
    const RawComment *rc = d->getASTContext().getRawCommentForDeclNoCache(d);
    if (rc)
    {
        SourceRange range = rc->getSourceRange();

        PresumedLoc startPos = sm.getPresumedLoc(range.getBegin());
        PresumedLoc endPos = sm.getPresumedLoc(range.getEnd());

        std::string raw = rc->getBriefText(d->getASTContext());
        return (raw.find("CAPA:IGNORE") != std::string::npos);
    }
    return false;
}
