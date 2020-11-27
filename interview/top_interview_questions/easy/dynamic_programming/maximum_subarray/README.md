# memo

## Algorithm

- sum = nums[0], max = nums[0]
- index 1 から末尾までループ
  - sum + nums[i] > nums[i]となるとき
    - sum = sum + nums[i]で更新
    - 現在の maxと sumを比較し, sum > maxとなるとき max = numに更新
  - sum + nums[i] > nums[i]とならないとき 
    - sum = nums[i]に更新
    - 現在の maxと nums[i]を比較し, nums[i] > maxとなるとき max = nums[i]に更新
