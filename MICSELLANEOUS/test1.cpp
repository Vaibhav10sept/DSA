#include <bits/stdc++.h>
using namespace std;
Node mirror(Node node) {
    if (node == NULL) return NULL;
    mirror(node.left);
    mirror(node.right);
    swap(node.left.data, node.right.data);
}
int main() {


}
