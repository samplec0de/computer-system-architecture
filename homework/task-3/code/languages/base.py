import random
from string import printable
from typing import Optional, Union

from .functional import FunctionalLanguage
from ..common import IncorrectTypeError, NotEnoughTokensError

DEFAULT_LENGHT = 20


def random_string(length: int = DEFAULT_LENGHT):
    """Случайная строка заданной длины

    :param length: длина строки, по умолчанию DEFAULT_LENGHT=20
    """
    result_str = ''.join(random.choice(printable) for _ in range(length))
    return result_str


class BaseLanguage:
    """Базовый класс языка программирования"""
    def __init__(self):
        """Конструктор базового класса ЯП, создаёт поля и заполняет их None"""
        self._name: Optional[str] = None
        self._year_created: Optional[int] = None
        self._rating: Optional[Union[float, int]] = None

    @property
    def year_div_name_len(self) -> float:
        """Частное от деления года создания на количество символов в названии"""
        return self.year_created / len(self.name)

    @property
    def name(self):
        return self._name

    @name.setter
    def name(self, value):
        """Устанавливает значение имени ЯП

        :param value: новое значение

        :raises ValueError: если новое значение пустая строка
        """
        if value:
            self._name = value
        else:
            raise IncorrectTypeError(f"Name excepted to be non-empty string, but input empty")

    @property
    def year_created(self):
        return self._year_created

    @year_created.setter
    def year_created(self, value):
        """Устанавливает значение года создания

        :param value: новое значение

        :raises IncorrectTypeError: если новое значение не целое число
        """
        if value.isdigit():
            self._year_created = int(value)
        else:
            raise IncorrectTypeError(f"Year created excepted to be positive integer, but \"{value}\" is not")

    @property
    def rating(self):
        return self._rating

    @rating.setter
    def rating(self, value):
        """Устанавливает значение рейтинга TIOBE

        :param value: новое значение

        :raises IncorrectTypeError: если новое значение не дробное число
        """
        try:
            self._rating = float(value)
        except ValueError:
            raise IncorrectTypeError(f"TIOBE rating excepted to be float, but \"{value}\" is not")

    @staticmethod
    def from_line(line: str):
        """Ввод ЯП из строки с его описанием

        :param line: строка с описанием ЯП

        :raises IncorrectTypeError: при ошибке соответствия типов (например рейтинга или года)
        :raises NotEnoughTokensError: при недостаточности входных данных, когда не удается заполнить
                                      даже базовые поля (имя, год, рейтинг)
        :raises ValueError: если имя -- пустая строка
        :raises NotImplementedError: при некорректном типе языка
        """
        tokens = line.split()
        if len(tokens) < 3:
            raise NotEnoughTokensError("Base language must contain at least 3 tokens: "
                                       "name, TIOBE rating and created year")
        language_class = None
        lang_type = tokens[0]
        if lang_type == 'functional':
            language = FunctionalLanguage
        else:
            raise NotImplementedError(f"Language type {lang_type} incorrect")
        language.name = tokens[1]
        language.rating = tokens[2]
        language.year_created = tokens[3]
        language.fill_from_tokens(tokens=tokens[3:])

    def fill_randomly(self):
        """Рандомное заполнение информации о ЯП"""
        self.name = random_string()
