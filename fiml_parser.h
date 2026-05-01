#if !defined(FIML_PARSER_H)
#define FIML_PARSER_H

#include	<strval.h>
#include	<variant.h>
#include	<peg.h>
#include	<peg_ast.h>

class FimlParser
: public Peg<PegMemorySource, PegMatch, PegContext>
{
       static  Rule    rules[];
       static  int     num_rule;
public:
       FimlParser() : Peg(rules, num_rule) {}
};
#endif // FIML_PARSER_H
