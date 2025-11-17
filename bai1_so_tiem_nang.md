# Số tiềm năng

## Yêu cầu

Một số nguyên dương ~x~ được gọi là **số tiềm năng** nếu tổng các ước số dương của ~x~ **không kể chính nó** lớn hơn hoặc bằng ~x~.

$$
\sum_{\substack{d \mid x \\ d < x}} d \ge x
$$

Ví dụ:

- ~6~ là số tiềm năng vì các ước dương của nó (trừ chính nó) là: ~1, 2, 3~, tổng bằng ~6~.
- ~8~ **không** là số tiềm năng vì ~1 + 2 + 4 = 7 < 8~.

Cho ~Q~ truy vấn dạng ~[L, R]~.  
Nhiệm vụ của bạn là: **đếm số lượng số tiềm năng nằm trong đoạn từ ~L~ đến ~R~**.

## Dữ liệu

- Dòng 1: số nguyên dương ~Q~.  
- ~Q~ dòng tiếp theo, mỗi dòng chứa hai số nguyên dương ~L, R~.

## Kết quả

- Gồm ~Q~ dòng, dòng thứ ~i~ ghi số lượng số tiềm năng trong đoạn truy vấn thứ ~i~.

## Ví dụ

### Input
```
3
1 10
2 7
10 50
```

### Output
```
1
1
10
```

## Giải thích

- Đoạn ~[1,10]~ chỉ có duy nhất số ~6~ là số tiềm năng.  
- Đoạn ~[2,7]~ cũng chỉ có ~6~.  
- Đoạn ~[10,50]~ có tổng cộng 10 số thoả mãn định nghĩa số tiềm năng.

## Chấm điểm

- **30%** số test với ràng buộc: ~R \le 10^4~  
- **30%** số test với ràng buộc: ~R \le 10^6~  
- **40%** số test còn lại không có ràng buộc đặc biệt.
