#ifndef STRING_TOKENIZER_H
#define STRING_TOKENIZER_H
#include <string>

/** The string_tokenizer class splits a string into a sequence of subtrings,
    called tokens, separated by delimeters.
*/
class String_Tokenizer
{
 public:
  /** Construct a string_tokenizer
      @param source The string to be split into tokens
      @param delim The string containing the delimeters. If
      this parameter is omitted, a space character is assumed.
  */
  String_Tokenizer(std::string source, std::string delim=" ") :
    the_source(source), the_delim(delim), start(0), end(0) {find_next();}

  /** Determine if there are more tokens
      @return true if there are more tokens
  */
  bool has_more_tokens();

  /** Retrieve the next token
      @return The next token. If there are no more tokens, an empty
      string is returned.
  */
  std::string next_token();

 private:
  /** Position start and end so that start is the index of the start
      of the next token and end is the end.
  */
  void find_next();
  /** The string to be split into tokens */
  std::string the_source;
  /** The string of delimeters */
  std::string the_delim;
  /** The index of the start of the next token */
  size_t start;
  /** The index of the end of the next token*/
  size_t end;
};

#endif
