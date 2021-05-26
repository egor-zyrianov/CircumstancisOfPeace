# CircumstancisOfPeace
Algorithmic problem

Задача: Расстановка ферзей
Имя входного файла: input.txt
Имя выходного файла: output.txt
Ограничение по времени: 1 секунда
Ограничение по памяти: разумное
Дано прямоугольное клеточное поле из 𝑀 строк и 𝑁 столбцов. Нужно расставить ферзей
на этом поле согласно правилам:
1. В каждой строке поля должен стоять один ферзь.
2. Никакие два ферзя не должны бить друг друга.
Ферзи на поле бьют всё, что стоит на той же горизонтали, вертикали или диагонали (как
в шахматах). В некоторые клетки поля ставить ферзя запрещено.
Формат входных данных
В первых двух строках дано два целых числа: 𝑀 — количество строк и 𝑁 — количество столбцов
В остальных 𝑀 строках записана карта поля. Каждая из этих строк содержит ровно 𝑁
символов. Символ "__" означает, что в этой клетке можно ставить ферзя, а можно
не ставить. Символ точки "." означает, что в этой клетке ферзя ставить запрещено.
Формат выходных данных
Если искомого решения не существует, "retun 1", и больше ничего не
выводить.
Если решение существует, то "return 0" , и решение в
остальные 𝑀 строк. Решение должно быть выведено в виде карты поля, в том же формате,
как во входных данных. Только каждый символ вопроса надо заменить на X (заглавную
букву «икс»), если в этой клетке стоит ферзь, и "__" — если не стоит.
Если решений несколько, можно вывести любое из них.
