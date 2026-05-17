/*
 * Rules for a FimlParser
 *
 * You must declare this type in fiml_parser.h by expanding the Peg<> template
 */
#include	<fiml_parser.h>

const char*	TOP_captures[] = { "bom", "statement", 0 };
const char*	comparison_captures[] = { "comparison_operator", "expression", 0 };
const char*	comparison_operator_captures[] = { "op", 0 };
const char*	datum_captures[] = { "d", 0 };
const char*	value_captures[] = { "v", 0 };
const char*	struct_captures[] = { "k", "v", 0 };
const char*	array_captures[] = { "e", 0 };
const char*	boolean_literal_captures[] = { "v", 0 };
const char*	string_literal_captures[] = { "c", 0 };
const char*	number_captures[] = { "number", 0 };

FimlParser::Rule	FimlParser::rules[] =
{
	{ "TOP",
	  "?(<BOM>:bom:)*(?<s><statement>)",
	  TOP_captures
	},
	{ "BOM",
	  "\\uFEFF",
	  0
	},
	{ "statement",
	  "(|<concept>|<instance>|<query>|<generator>)<s>\\.?<white_to_eol>(|\\n|<EOF>)",
	  0
	},
	{ "EOF",
	  "!.",
	  0
	},
	{ "concept",
	  "Each<ss><name><ss>is<ss><concept_declaration>?(<ss><concept_property_list>)",
	  0
	},
	{ "concept_declaration",
	  "|a<ss>concept|<concept_supertype>?(<ss><concept_type>)|<concept_type>",
	  0
	},
	{ "concept_supertype",
	  "a<ss>kind<ss>of<ss><name>",
	  0
	},
	{ "concept_type",
	  "|<object_type_declaration>|<data_type_declaration>",
	  0
	},
	{ "object_type_declaration",
	  "|<entity_type_declaration>|<fact_type_declaration>",
	  0
	},
	{ "entity_type_declaration",
	  "identified<ss>by<ss><identifier_list>",
	  0
	},
	{ "fact_type_declaration",
	  "where<ss><fact_type>",
	  0
	},
	{ "data_type_declaration",
	  "written<ss>as<ss><data_type>",
	  0
	},
	{ "identifier_list",
	  "<identifier>*(<sep><identifier>)",
	  0
	},
	{ "identifier",
	  "<item>",
	  0
	},
	{ "concept_property_list",
	  "and<ss><pronoun><ss><property>*(<sep><property>)",
	  0
	},
	{ "pronoun",
	  "|it|they",
	  0
	},
	{ "fact_type",
	  "<reading>+(<s>/<s><reading>)",
	  0
	},
	{ "reading",
	  "|?(<preamble><ss>)+(<role><ss><predicator><ss>)<quantified_role>?(<ss><postamble>)|<role><ss><predicator>",
	  0
	},
	{ "property",
	  "<property_reading>?(<s>/<s><role><ss><property_reading>)",
	  0
	},
	{ "property_reading",
	  "<predicator><ss><quantified_role>?(<ss><postamble>)",
	  0
	},
	{ "quantified_role",
	  "?(<quantifier><ss>)<role>",
	  0
	},
	{ "role",
	  "<item>",
	  0
	},
	{ "item",
	  "|<name>?(<ss>\\(<s><name><s>\\))|<adjective><ss><name>",
	  0
	},
	{ "name",
	  "[\\U]+[\\L\\d]*(&(<ss>[\\U]+[\\L\\d])<ss>[\\U]+[\\L\\d])",
	  0
	},
	{ "preamble",
	  "<predicate_words>",
	  0
	},
	{ "predicator",
	  "<predicate_words>",
	  0
	},
	{ "postamble",
	  "<predicate_words>",
	  0
	},
	{ "predicate_words",
	  "!<reserved_words>+[\\L]*(<ss>!<reserved_words>+[\\L])",
	  0
	},
	{ "reserved_words",
	  "|<quantifier>|<adjective>",
	  0
	},
	{ "adjective",
	  "+[\\L]-*(<ss>+[\\L])",
	  0
	},
	{ "quantifier",
	  "|one|at<ss>most<ss>one|at<ss>least<ss>one|many|where|group<ss>by",
	  0
	},
	{ "instance",
	  "<name>\\:<ss><instance_body>",
	  0
	},
	{ "instance_body",
	  "|<datum>|\\(<s><instance_literal><s>\\)",
	  0
	},
	{ "instance_literal",
	  "<name><object_reference>?(<property_literal>*(<sep><property_literal>))",
	  0
	},
	{ "property_literal",
	  "<predicator><ss><role_literal>?(<ss><postamble>)",
	  0
	},
	{ "fact",
	  "|<role_literal><ss><predicator>|?(<preamble><ss>)+(<role_literal><ss><predicator><ss>)<role_literal>?(<ss><postamble>)",
	  0
	},
	{ "role_literal",
	  "|?(<name><ss>)<datum>|<name><ss><object_reference>",
	  0
	},
	{ "object_reference",
	  "|<keyed_datum_list>|\\(<s><fact><s>\\)",
	  0
	},
	{ "keyed_datum_list",
	  "\\{<s><keyed_datum>*(<sep><keyed_datum>)<s>\\}",
	  0
	},
	{ "keyed_datum",
	  "<key>\\:<ss><datum>",
	  0
	},
	{ "key",
	  "[\\L]*[\\L\\d]*([_][\\L]*[\\L\\d])",
	  0
	},
	{ "query",
	  "?(<with_generators><ss>)[Ff]or<ss>each<ss><path><path_control><s>=><s><selector>",
	  0
	},
	{ "path",
	  "<object_template><ss><variable><ss><step_body>*(<sep><step>)",
	  0
	},
	{ "step",
	  "?(<subject><ss>)<step_body>",
	  0
	},
	{ "step_body",
	  "<predicator><ss><roled_expression>?(<ss><postamble>)",
	  0
	},
	{ "object_template",
	  "<name>?(<object_selector>)",
	  0
	},
	{ "object_selector",
	  "|<keyed_expression_list>|\\(<s><fact_template><s>\\)",
	  0
	},
	{ "subject",
	  "|<relative_pronoun>|?(<object_template><ss>)<variable>",
	  0
	},
	{ "relative_pronoun",
	  "|that|who",
	  0
	},
	{ "variable",
	  "+[\\U]",
	  0
	},
	{ "roled_expression",
	  "|<object_template><ss><variable>|?(<name><ss>)<expression>",
	  0
	},
	{ "path_control",
	  "?(<ss><where_condition>)?(<ss><grouping>)",
	  0
	},
	{ "where_condition",
	  "where<ss><boolean_expression>",
	  0
	},
	{ "grouping",
	  "<group_by><ss>?<group_condition>",
	  0
	},
	{ "group_by",
	  "group<ss>by<ss><name>*(<sep><name>)",
	  0
	},
	{ "group_condition",
	  "having<ss><boolean_expression>",
	  0
	},
	{ "selector",
	  "|<keyed_expression_list>|\\(<s><instance_template><s>\\)",
	  0
	},
	{ "keyed_expression_list",
	  "\\{<s><keyed_expression>*(<sep><keyed_expression>)<s>\\}",
	  0
	},
	{ "keyed_expression",
	  "<key>\\:<ss><expression>",
	  0
	},
	{ "instance_template",
	  "<object_template>?(<ss><property_template>*(<sep><property_template>))",
	  0
	},
	{ "property_template",
	  "<predicator><ss><roled_expression>?(<ss><predicator>)",
	  0
	},
	{ "fact_template",
	  "?(<preamble><ss>)+(<roled_expression><ss><predicator><ss>)<roled_expression>?(<ss><postamble>)",
	  0
	},
	{ "fact_template_loop",
	  "&(<fact_template_step><ss><roled_expression>)<fact_template_step><ss>",
	  0
	},
	{ "fact_template_step",
	  "<roled_expression><ss><predicator>",
	  0
	},
	{ "generator",
	  "<name>\\:<ss>\\(<s><query><s>\\)",
	  0
	},
	{ "with_generators",
	  "[Ww]ith<ss><generator_list>",
	  0
	},
	{ "generator_list",
	  "<generator>+(<sep><generator>)",
	  0
	},
	{ "data_type",
	  "|<value_type>|a<ss>struct<ss>containing<ss><element_list>|an<ss>array<ss>of<ss><data_type>",
	  0
	},
	{ "element_list",
	  "\\{<s><element>*(<sep><element>)<s>\\}",
	  0
	},
	{ "element",
	  "<item>",
	  0
	},
	{ "value_type",
	  "<builtin_value_type>",
	  0
	},
	{ "builtin_value_type",
	  "|Number|String|Boolean|Date Time",
	  0
	},
	{ "expression",
	  "|<accessor_expression>|<numeric_expression>|<string_expression>|<boolean_expression>",
	  0
	},
	{ "accessor_expression",
	  "<variable>*(|\\.<key>|\\[<s><numeric_expression><s>\\])",
	  0
	},
	{ "numeric_expression",
	  "<numeric_term>*(<s><addition_operator><s><numeric_term>)",
	  0
	},
	{ "addition_operator",
	  "|\\+|-",
	  0
	},
	{ "numeric_term",
	  "<numeric_factor>*(<s><multiplication_operator><s><numeric_factor>)",
	  0
	},
	{ "multiplication_operator",
	  "|\\*|/",
	  0
	},
	{ "numeric_factor",
	  "|<number>|?-<accessor_expression>|\\(<s><numeric_expression><s>\\)",
	  0
	},
	{ "string_expression",
	  "<string_term>*(<s>\\+<s><string_term>)",
	  0
	},
	{ "string_term",
	  "|<string_literal>|<accessor_expression>|\\(<s><string_expression><s>\\)",
	  0
	},
	{ "boolean_expression",
	  "<and_expression>*(<ss>or<ss><and_expression>)",
	  0
	},
	{ "and_expression",
	  "<not_expression>*(<ss>and<ss><not_expression>)",
	  0
	},
	{ "not_expression",
	  "?(not)<ss><boolean_factor>",
	  0
	},
	{ "boolean_factor",
	  "|<boolean_literal>|<comparison>|<accessor_expression>|exists<ss>\\(<s><query><s>\\)|\\(<s><boolean_expression><s>\\)",
	  0
	},
	{ "comparison",
	  "<expression><s><comparison_operator><s><expression>",
	  comparison_captures
	},
	{ "comparison_operator",
	  "|<equal_to_operator>:op:|<not_equal_to_operator>:op:|<less_or_equal_operator>:op:|<less_than_operator>:op:|<greater_or_equal_operator>:op:|<greater_than_operator>:op:",
	  comparison_operator_captures
	},
	{ "equal_to_operator",
	  "=![>]",
	  0
	},
	{ "not_equal_to_operator",
	  "|\\<>|\\!=",
	  0
	},
	{ "less_than_operator",
	  "\\<!=",
	  0
	},
	{ "less_or_equal_operator",
	  "\\<=",
	  0
	},
	{ "greater_or_equal_operator",
	  ">=",
	  0
	},
	{ "greater_than_operator",
	  ">![=<]",
	  0
	},
	{ "datum",
	  "|<value>:d:|<struct>:d:|<array>:d:",
	  datum_captures
	},
	{ "value",
	  "|<boolean_literal>:v:|<string_literal>:v:|<number>:v:",
	  value_captures
	},
	{ "struct",
	  "\\{(|(<s><key>:k:\\:<ss><datum>:v:*(<sep><key>:k:\\:<ss><datum>:v:)<s>)|<s>)\\}",
	  struct_captures
	},
	{ "array",
	  "\\[(|(<s><datum>:e:*(<sep><datum>:e:)<s>)|<s>)\\]",
	  array_captures
	},
	{ "boolean_literal",
	  "|true:v:!\\w|false:v:!\\w",
	  boolean_literal_captures
	},
	{ "string_literal",
	  "\\\'*(<string_char>:c:)\\\'",
	  string_literal_captures
	},
	{ "string_char",
	  "|\\\\[befntr\\\\\']|\\\\[0-7][0-7][0-7]|\\\\*[\\r][\\n]*[\\r]|\\\\0|\\\\x[0-9A-Fa-f][0-9A-Fa-f]|\\\\u[0-9A-Fa-f][0-9A-Fa-f][0-9A-Fa-f][0-9A-Fa-f]|![\'\\x01-\\x07\\x0A-\\x1F].",
	  0
	},
	{ "number",
	  "(|<integer>:number:|<real>:number:|<fractional_real>:number:|<hex_number>:number:|<octal_number>:number:)!\\w",
	  number_captures
	},
	{ "integer",
	  "?[-+][1-9]*[0-9]",
	  0
	},
	{ "real",
	  "?[-+][1-9]*[0-9]?<fraction>?<exponent>",
	  0
	},
	{ "fractional_real",
	  "?[-+]0<fraction>?<exponent>",
	  0
	},
	{ "fraction",
	  "\\.+[0-9]",
	  0
	},
	{ "exponent",
	  "[Ee]?[-+]+[0-9]",
	  0
	},
	{ "hex_number",
	  "0x+[0-9A-Fa-f]",
	  0
	},
	{ "octal_number",
	  "0*[0-7]",
	  0
	},
	{ "sep",
	  ",<s>",
	  0
	},
	{ "comment_to_eol",
	  "//*(!(\\n).)",
	  0
	},
	{ "comment_c_style",
	  "/\\**(!(\\*/).)\\*/",
	  0
	},
	{ "whitespace",
	  "|+[ \\t\\n\\r]|<comment_to_eol>|<comment_c_style>",
	  0
	},
	{ "white_to_eol",
	  "|+[ \\t\\r]|<comment_to_eol>|<comment_c_style><white_to_eol>",
	  0
	},
	{ "s",
	  "*<whitespace>",
	  0
	},
	{ "ss",
	  "+<whitespace>",
	  0
	}
};

int	FimlParser::num_rule = sizeof(FimlParser::rules)/sizeof(FimlParser::rules[0]);
