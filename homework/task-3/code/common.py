from random import choice
from string import printable

DEFAULT_LENGHT = 20


def get_random_string(length: int = DEFAULT_LENGHT):
    """Случайная строка заданной длины

    :param length: длина строки, по умолчанию DEFAULT_LENGHT=20
    """
    result_str = ''.join(choice(printable) for _ in range(length))
    return result_str
