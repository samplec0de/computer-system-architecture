class ParseError(Exception):
    pass


class NotEnoughTokensError(ParseError):
    pass


class IncorrectTypeError(ParseError):
    pass
