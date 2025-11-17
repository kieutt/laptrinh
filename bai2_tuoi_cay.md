# Tưới cây

Một khu vườn gồm ~n~ luống cây được trồng thẳng hàng. Hệ thống tưới nước tự động được theo dõi trong một khoảng thời gian và ghi lại trạng thái của từng luống cây:

- Trạng thái ~1~: luống cây đã được tưới đủ nước.
- Trạng thái ~0~: luống cây đang bị khô.

Bác nông dân John có thể tưới thủ công tối đa ~k~ luống cây khô để đạt một đoạn liên tiếp dài nhất toàn các luống được tưới đủ nước.

## Yêu cầu

Cho dãy trạng thái ~a_1, a_2, \ldots, a_n~ với mỗi ~a_i \in \{0,1\}~ và số nguyên ~k~.  
Hãy xác định **độ dài lớn nhất của một đoạn con liên tiếp** sao cho sau khi tưới (không quá ~k~ luống khô), đoạn đó toàn giá trị ~1~.

## Dữ liệu

- Dòng 1: hai số nguyên ~n, k~.  
- Dòng 2: ~n~ số ~a_i~ (~0~ hoặc ~1~).

## Kết quả

Một số nguyên duy nhất: độ dài đoạn liên tiếp lớn nhất toàn ~1~ sau khi được phép tưới tối đa ~k~ luống khô.

## Ví dụ

### Input
```
10 2
1 0 1 1 1 0 1 0 0 1
```

### Output
```
7
```

## Giải thích

Bằng cách tưới thêm 2 luống khô thích hợp, ta có thể tạo thành đoạn liên tiếp dài nhất gồm 7 luống đều có trạng thái ~1~.

## Chấm điểm

- 30% số test có ràng buộc nhỏ  
- 30% số test có ràng buộc trung bình  
- 40% số test không có ràng buộc đặc biệt
