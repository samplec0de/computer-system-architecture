import random
from string import printable
from typing import Optional, Union

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
        self.name: Optional[str] = None
        self.year_created: Optional[int] = None
        self.rating: Optional[Union[float, int]] = None

    @property
    def year_div_name_len(self) -> float:
        """Частное от деления года создания на количество символов в названии"""
        return self.year_created / len(self.name)

    def fill_from_line(self, string: str):
        """Ввод ЯП из строки с его описанием

        :param string: строка с описанием ЯП
        """
        pass

    def fill_randomly(self):
        """Рандомное заполнение информации о ЯП"""
        self.name = random_string()
