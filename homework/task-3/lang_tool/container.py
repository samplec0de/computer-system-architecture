from pathlib import Path
from typing import Optional, Union, List

from lang_tool.languages.functional import FunctionalLanguage
from lang_tool.common.exceptions import NotEnoughTokensError
from lang_tool.languages.object_oriented import ObjectOrientedLanguage
from lang_tool.languages.procedure import ProcedureLanguage
from lang_tool.languages.types import LanguageType


class Container:
    """Класс контейнера ЯП"""
    def __init__(self, filename: Optional[str] = None, n_random: Optional[int] = None):
        self.languages: List[Union[FunctionalLanguage]] = []
        if filename:
            for line in Path(filename).read_text().splitlines():
                language = self.language_from_line(line)
                self.languages.append(language)

    @staticmethod
    def language_from_line(line: str) -> Union[FunctionalLanguage]:
        """Ввод ЯП из строки с его описанием

        :param line: строка с описанием ЯП

        :raises NotEnoughTokensError: при недостаточности входных данных, когда не удается заполнить
                                      даже базовые поля (имя, год, рейтинг) или дополнительные поля конкретного вида ЯП
        :raise TooManyTokensError: при наличии лишних данных, не предназначенных для конкретного вида ЯП
        :raises ValueError: если имя -- пустая строка или при ошибке заполнения поля конкретного вида ЯП
        :raises NotImplementedError: при некорректном типе языка
        """
        tokens = line.split()
        if len(tokens) < 3:
            raise NotEnoughTokensError("Base language must contain at least 3 tokens: "
                                       "name, TIOBE rating and created year")
        lang_type = tokens[0]
        language = None
        if LanguageType(lang_type) == LanguageType.FUNCTIONAL:
            language = FunctionalLanguage()
        elif LanguageType(lang_type) == LanguageType.PROCEDURE:
            language = ProcedureLanguage()
        elif LanguageType(lang_type) == LanguageType.OBJECT_ORIENTED:
            language = ObjectOrientedLanguage()
        language.name = tokens[1]
        language.rating = tokens[2]
        language.year_created = tokens[3]
        language.fill_from_tokens(tokens=tokens[4:])
        return language
