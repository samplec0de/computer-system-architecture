from enum import Enum
from typing import List

from .base import BaseLanguage


class Typing(Enum):
    STRICT = 'strict'
    DYNAMIC = 'dynamic'


class FunctionalLanguage(BaseLanguage):
    def __init__(self):
        super().__init__()

    def fill_from_tokens(self, tokens: List[str]):
        """Заполняет информацию о функциональном ЯП"""
        pass
