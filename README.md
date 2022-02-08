# math1
![cau hoi](https://user-images.githubusercontent.com/29473579/147653652-2572cbd3-c55b-4148-87f4-ac656a96e215.jpg)

My ans:

   Ý tưởng giải: ở file "mophong.pdf".
   
   Code: ở file "beauty_modified.cpp".
   
   Thời gian chạy ra kết quả với n = 3 đến 110: ở file "thời gian"
   
   Kết quả: Biểu đồ mối liên hệ giữa n và số nhóm con của nhóm Z^x_n. Với n từ 3 đến 105.
            Dùng Matlab để vẽ đồ thị.
  
   ![kq105](https://user-images.githubusercontent.com/29473579/147655173-52be3557-a303-4e20-a5e9-a02a37a0b098.png)
Quá trình giải: mình không nghĩ ra ý tưởng ngay từ đầu mà mình bắt đầu bằng việc xử lí những câu hỏi ở level thấp hơn.

Level 1: Implement in C++

    Bài 1. Cho 2 số nguyên dương a,b. Tính gcd(a,b).
         C1: code ra với thuật toán Euclid.
         C2: dùng câu lệnh trong thư viện (độ phức tạp cx sẽ là thuật toán Euclid).
    
    Bài 2. Cấu trúc dữ liệu để mô tả 1 tập con:
        a. vector<int> 
        b. set<int>
        c. vector<int> ( dạng đếm)
        VD: tập A = {1,2,5} 
        thì vector<int> a là mảng [1,2,5]
            set<int> b là cây nhị phân với 3 đỉnh được gắn số lên đỉnh là 1,2,5.
            vector<int> dạng đếm của A là [0,1,1,0,0,1] , 
               khi đó c[1] = c[2] = c[5] = 1,
               các vị trí còn lại = 0.
        
    Bài 3. Cho số nguyên dương n. Tìm tất cả các số nguyên tố cùng nhau với n, nhỏ hơn n.
    
    Bài 4. Cho 2 số nguyên dương a,b. Tính (a*b) mod n.
    
    Bài 5. Cho 1 tập hợp A. In ra các phần tử của A
    
Level 2: Kiểm tra xem 1 tập hợp có là tập con đẹp ko.
    
    Bài 1. Cho tập con A. Kiểm tra xem có phải với mọi u,v thuộc A thì u*v cũng thuộc A ko?
    
            Cách làm : for trâu O(n^2).
            
            Tốn O(n^2).
            
    Bài 2. Cho tập con A. Làm thế nào để sinh ra tập con đẹp từ tập A này?
            C1: Làm như ở bài 1 (nhưng phải thêm cái (u*v) vào)  hữu hạn lần đến khi ko còn phần tử mới nữa.
                 Tốn O(n^3).
            C2: Ta xếp các phần tử của A thành dãy, giả sử là a1,a2,a3,a4.
                   Ta cho con trỏ chạy từ 1. Ta sẽ kiểm tra các bộ (a_trỏ * phần tử đứng trước nó) : 
                            a_trỏ * a_1, a_trỏ *a_2,.... a_trỏ*a_trỏ, xem có phần tử nào mới ko.
                           Nếu có, cho vào vị trí cuối trong dãy.
                  Cứ thế làm đến khi trỏ = độ dài của tập con.
                 Tốn O(n^2). 
                   
Level 3: Từ tập con {a1},{a2},... với a_i nguyên tố cnhau với n, tìm tập con đẹp sinh ra bởi chúng.

            Để tránh việc ta đã kiểm tra xong tập A rồi mà 
            ta lại kiểm tra tập A lần nữa,
             ta dùng 1 cấu trúc dữ liệu để đánh dấu lại.
            Trong C++, có thể dùng map.
            A có các trường hợp:
               1. Chưa kiểm tra
               2. Đã kiểm tra, đẹp
               3. Đã kiểm tra, chưa đẹp.
            
            Ta cứ tiếp tục quá trình như ở Level 2, bài 2,
            khi nào gặp tập đã kiểm tra thì ta dừng lại.
            Kết thúc, nếu tập vẫn là "Chưa kiểm tra" 
            thì ta tô màu "đã kiểm tra, đẹp" vào
            tập đó.
  
            
Level 4: Tiếp tục tìm các tập con đẹp mà sinh bởi nhiều hơn 1 phần tử
        
        Ta thấy mình có thể tận dụng câu hỏi ở Level 3,
        bằng cách ghép các tập con đẹp đó rồi kiểm tra theo cách ở level 2 (bài 2).
       




