/*
 * https://femida.yandex-team.ru/problems/4174
 *
 * Дано бинарное дерево с выделенным корнем, в каждой вершине которого записано по одной букве A-Z.
 * Две вершины считаются эквивалентными, если поддеревья этих вершин содержат одинаковое множество (т.е. без учета частот) букв.
 * Нужно найти любую пару эквивалентных вершин.
 *
 * Можно усложнить, задав:
 * Нужно найти две эквивалентные вершины с максимальным суммарным размеров поддеревьев.
 */

#include <iostream>

using namespace std;

struct TNode {
    char Value;
    TNode* Left = nullptr;
    TNode* Right = nullptr;
};

TNode* ReadTree();
pair<TNode*, TNode*> FindEquivalentSubtrees(TNode* root);

int main(void) {
    TNode root = ReadTree();
    pair<TNode*, TNode*> subtrees = FindEquivalentSubtrees(root);
    
}

TNode* ReadTree() {
    int nodes_count;
    cin >> nodes_count;
    while (nodes_count--) {
        
    }
}


/*
1. Поиск в глубину, для каждой вершины получаем множество букв
множество букв --> 'хэш', в map добавляем пару 'хэш' => вершина
если в map уже есть вершина с хэш => нашли

 */

/*
Решение за O(NK), где N - размер дерева, K - размер алфавита.
То есть, обход дерева с построением дескриптора (булева массива размера K) поддерева
и отображения - дескриптор->два максимальных поддерева с этим дескриптором.
Можно поддерживать мап из декскриптора в максимальное поддерево с таким дескриптором и обновлять пару с максимальной суммой каждый раз,
когда мы пытаемся обновить в мапе максимум.
Так писать даже проще.
Хороший кандидат в качестве дескриптора использует битовую маску встреченных букв и получит сложность O(N).
 */