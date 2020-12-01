# memo

- 再帰で簡単に表現できそうだが, 問題の条件が 10,000ノードまでとあり, 最悪のケース(すべてのノードが直線的につながり実質リストとなるとき)を考慮するとスタックあふれの可能性があることを考慮し, ループで解いた
- 解法
  - `root node == nullptr` の場合 0を返す
  - stackを用意. 要素は node + その nodeの深さを保持するもの
    - root nodeを追加
  - ループ stackが空まで
    - nodeを取り出し, stackを pop
    - その nodeの深さと現在の最大の深さを比較し, 前者が大きい場合は最大の深さを更新
    - `node->left` が not nullptrの場合, stackに `node->left, node_depth + 1` を積む
    - `node->right` が not nullptrの場合, stackに `node->right, node_depth + 1` を積む
    - ループ先頭に戻る
  - 最大の深さを返す
