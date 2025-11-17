# Độ đẹp dãy con

Một dãy gồm ~n~ số nguyên dương ~a_1, a_2, \ldots, a_n~.  
Một **đoạn con liên tiếp** là đoạn ~[L, R]~ với ~1 \le L \le R \le n~.

**Độ đẹp** của đoạn con ~[L, R]~ được định nghĩa là:

$$
\max(a_L, \ldots, a_R) \, - \, \min(a_L, \ldots, a_R)
$$

---

## Yêu cầu

Hãy tính **tổng độ đẹp của tất cả các đoạn con** của dãy ~a~.

---

## Dữ liệu

- Dòng 1: số nguyên dương ~n~.  
- Dòng 2: ~n~ số nguyên dương ~a_1, a_2, \ldots, a_n~.

---

## Kết quả

- Một số nguyên duy nhất: tổng độ đẹp của **tất cả** các đoạn con của dãy.

---

## Ví dụ

### Input
```
4
2 1 5 3
```

### Output
```
19
```

---

## Giải thích

Tổng cộng có \( \frac{n(n+1)}{2} = 10 \) đoạn con.  
Tính độ đẹp cho mọi đoạn và cộng lại thu được kết quả bằng **19**.

---

## Chấm điểm

- **30%** số test với ràng buộc nhỏ.  
- **30%** số test với ràng buộc trung bình.  
- **40%** số test còn lại không có ràng buộc đặc biệt.

