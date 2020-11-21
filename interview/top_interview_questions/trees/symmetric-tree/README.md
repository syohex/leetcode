# memo

- root == nullptrの場合 trueを返す
- 木を左側(r1), 右側(r2)で同時にたどっていく
  - `r1->left != nullptr` の場合
    - `r2->right == nullptr` であれば falseを返す
    - 左の木を `r1->left`, 右の木 `r2->right` とたどる
  - `r1->left == nullptr` の場合
    - `r2->right != nullptr` であれば falseを返す
  - `r2->right != nullptr` の場合
    - `r2->left == nullptr` であれば falseを返す
    - 左の木を `r1->right`, 右の木 `r2->left` とたどる
  - `r1->right == nullptr` の場合
    - `r2->left != nullptr` であれば falseを返す
