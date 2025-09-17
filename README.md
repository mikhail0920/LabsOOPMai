# Лабораторная №1

## Задание
Нужно написать функцию **`closest_pair_tonum`**, которая принимает целочисленное значение `upper_limit` и возвращает пару значений `(m, n)` таких, что:

- `m + n = k²` для некоторого целого `k`
- `m - n = l²` для некоторого целого `l`
- выполняется неравенство:

  <img src="https://latex.codecogs.com/svg.image?\;upper\_limit%3Em%3En%3E0\"/>

При этом пара `(m, n)` должна быть **максимальной** (по `m`, а если несколько кандидатов — то по `n`).

---

## Идеи
Из условий:
  <img src="https://latex.codecogs.com/svg.image?\;m&plus;n=k^2,\quad&space;m-n=l^2"/>

Складывая и вычитая, получаем:
<img src="https://latex.codecogs.com/svg.image?\;m=\frac{k^2&plus;l^2}{2},\quad&space;n=\frac{k^2-l^2}{2}"/>

Задача сводится к перебору подходящих пар квадратов <img src="https://latex.codecogs.com/svg.image?\(k^2,l^2\)"/>.

---

## Ограничения
1. \(m\) и \(n\) должны быть целыми числами. Это значит, что <img src="https://latex.codecogs.com/svg.image?\(k^2&plus;l^2)\"/> и <img src="https://latex.codecogs.com/svg.image?(k^2-l^2)"/> обязаны быть чётными.  
2. Должно выполняться условие:  
   <img src="https://latex.codecogs.com/svg.image?&space;m%3Cupper\_limit,\quad&space;n%3E0&space;"/>
3. Так как:  
   <img src="https://latex.codecogs.com/svg.image?&space;m=\frac{k^2&plus;l^2}{2}%3Cupper\_limit&space;"/> 
   достаточно рассматривать:  <img src="https://latex.codecogs.com/svg.image?&space;k\leq\sqrt{2\cdot&space;upper\_limit}"/>

---

## Алгоритм
1. Вычисляем <img src="https://latex.codecogs.com/svg.image?max\_k=\sqrt{2\cdot&space;upper\_limit}"/>.  
2. Перебираем `k` от `max_k` вниз до 1.  
3. Для каждого \(k\) перебираем \(l\) от \(k-1\) вниз до 1.  
4. Считаем:  
   <img src="https://latex.codecogs.com/svg.image?&space;m=\frac{k^2&plus;l^2}{2},\quad&space;n=\frac{k^2-l^2}{2}"/>
5. Проверяем условия: `m` и `n` целые, <img src="https://latex.codecogs.com/svg.image?\(m%3Cupper\_limit\),\(n%3E0\)"/>.  
6. Среди всех подходящих пар выбираем максимальную (сначала по `m`, при равенстве — по `n`).  

---

## Сложность
Всего рассматривается порядка:
<img src="https://latex.codecogs.com/svg.image?&space;O(\sqrt{upper\_limit}^2)=O(upper\_limit)"/>
комбинаций, что существенно быстрее наивного перебора всех пар `(m, n)`, который имел бы сложность <img src="https://latex.codecogs.com/svg.image?O(upper\_limit^2)"/>.

---

## Тесты
Для проверки корректности использованы **Google Test**. Этот фреймворк позволяет писать структурированные юнит-тесты, запускать их пакетно и получать удобный вывод о результатах.  

Написаны следующие тесты:
- **SmallLimit (1)** — проверка ситуации, когда решений не существует. Ожидается `(-1, -1)`.  
- **Limit10** — проверка небольшого числа, решение `(5, 4)`.  
- **Limit30** — проверка среднего числа, решение `(29, 20)`.  
- **Limit50** — проверка большего числа, решение `(45, 36)`.  

Таким образом, тесты покрывают как граничные случаи (малые значения, отсутствие решения), так и корректность работы алгоритма на разных диапазонах входных данных.

---

## Инструкция по запуску
1. ```git clone https://github.com/mikhail0920/LabsOOPMai```.  
2. ```bash
   git checkout lab1```
3. Запуск возможен двумя способами:
   - Использовать уже собранный файл `test_runner.exe`.  
   - Собрать проект самостоятельно командой:  
     ```bash
     g++ -std=c++17 closest_pair.cpp test.cpp -Igoogletest/googletest/include -Lgoogletest/build/lib -lgtest -lgtest_main -pthread -o test_runner.exe
     ```
4. Запустить:
   ```bash
   ./test_runner.exe

(Обратите внимание, что требуется версия g++, поддерживающая C++17)
