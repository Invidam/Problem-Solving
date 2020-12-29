Ri:1 j:6
 1.r(1 6)
	temp: 1 
2.r(1 6)temp: 1Ri:3 j:1
	 1.r(3 1)
			temp: 1Ci:2 j:3
	 1.c(2 3)temp: 1 2.c(2 3)temp: 1 3.c(2 3)temp: 1Ci:2 j:3 ret : 1 s1 :2 s2 : 0 r : 1 ,c : 8
		
	 2.r(3 1)
			temp: 1Ci:5 j:4
	 1.c(5 4)temp: 1 2.c(5 4)temp: 1 3.c(5 4)temp: 1Ci:5 j:4 ret : 1 s1 :4 s2 : 0 r : 4 ,c : 8
	 3.r(3 1)
			temp: 1Ri:3 j:1 ret : 1 s1 :2 s2 : 0 r : 6 ,c : 8
	Ci:3 j:1
	 1.c(3 1)temp: 1 2.c(3 1)temp: 0Ci:5 j:4
	 1.c(5 4)temp: 1 2.c(5 4)temp: 0 3.c(5 4)temp: 0 3.c(3 1)temp: 0Ci:5 j:4
	 1.c(5 4)temp: 1Ri:3 j:1
	 1.r(3 1)temp: 1 2.r(3 1)temp: 0 3.r(3 1)temp: 0 2.c(5 4)temp: 0 3.c(5 4)temp: 0 
3.r(1 6)temp: 1Ri:1 j:6 ret : 1 s1 :0 s2 : 0 r : 8 ,c : 8
Ri:3 j:1
 1.r(3 1)temp: 1Ci:2 j:3
 1.c(2 3)temp: 1 2.c(2 3)temp: 1Ri:1 j:6
 1.r(1 6)temp: 1 2.r(1 6)temp: 1 3.r(1 6)temp: 1Ri:1 j:6 ret : 1 s1 :0 s2 : 4 r : 3 ,c : 4
 3.c(2 3)temp: 1Ci:2 j:3 ret : 1 s1 :0 s2 : 0 r : 3 ,c : 8
 2.r(3 1)temp: 1Ci:5 j:4
 1.c(5 4)temp: 1 2.c(5 4)temp: 1 3.c(5 4)temp: 1Ci:5 j:4 ret : 1 s1 :4 s2 : 0 r : 4 ,c : 8
 3.r(3 1)temp: 1Ri:3 j:1 ret : 2 s1 :0 s2 : 0 r : 8 ,c : 8
Ci:3 j:1
 1.c(3 1)temp: 1 2.c(3 1)temp: 0Ri:1 j:6
 1.r(1 6)temp: 1 2.r(1 6)temp: 1Ci:5 j:4
 1.c(5 4)temp: 1 2.c(5 4)temp: 0 3.c(5 4)temp: 0 3.r(1 6)temp: 0Ci:5 j:4
 1.c(5 4)temp: 1 2.c(5 4)temp: 0Ri:1 j:6
 1.r(1 6)temp: 1 2.r(1 6)temp: 1 3.r(1 6)temp: 0 3.c(5 4)temp: 0 3.c(3 1)temp: 0Ci:5 j:4
 1.c(5 4)temp: 1Ri:3 j:1
 1.r(3 1)temp: 1 2.r(3 1)temp: 0 3.r(3 1)temp: 0 2.c(5 4)temp: 0Ri:1 j:6
 1.r(1 6)temp: 1 2.r(1 6)temp: 1 3.r(1 6)temp: 0 3.c(5 4)temp: 02
Success #stdin #stdout 0s 4900KB
Ri:1 j:6
 1.r(1 6)temp: 1 2.r(1 6)temp: 1Ri:3 j:1
 1.r(3 1)temp: 1Ci:2 j:3
 1.c(2 3)temp: 1 2.c(2 3)temp: 1 3.c(2 3)temp: 1Ci:2 j:3 ret : 1 s1 :2 s2 : 0 r : 1 ,c : 8
 2.r(3 1)temp: 1Ci:5 j:4
 1.c(5 4)temp: 1 2.c(5 4)temp: 1 3.c(5 4)temp: 1Ci:5 j:4 ret : 1 s1 :4 s2 : 0 r : 4 ,c : 8
 3.r(3 1)temp: 1Ri:3 j:1 ret : 1 s1 :2 s2 : 0 r : 6 ,c : 8
Ci:3 j:1
 1.c(3 1)temp: 1 2.c(3 1)temp: 0Ri:3 j:4
 1.r(3 4)temp: 1 2.r(3 4)temp: 0Ci:5 j:4
 1.c(5 4)temp: 1 2.c(5 4)temp: 1 3.c(5 4)temp: 1Ci:5 j:4 ret : 1 s1 :4 s2 : 2 r : 4 ,c : 6
 3.r(3 4)temp: 0Ci:3 j:4
 1.c(3 4)temp: 1 2.c(3 4)temp: 0 3.c(3 4)temp: 0 3.c(3 1)temp: 0Ci:3 j:4
 1.c(3 4)temp: 1Ri:3 j:1
 1.r(3 1)temp: 1 2.r(3 1)temp: 0 3.r(3 1)temp: 0 2.c(3 4)temp: 0 3.c(3 4)temp: 0 3.r(1 6)temp: 1Ri:1 j:6 ret : 1 s1 :0 s2 : 0 r : 8 ,c : 8
Ri:3 j:1
 1.r(3 1)temp: 1Ci:2 j:3
 1.c(2 3)temp: 1 2.c(2 3)temp: 1Ri:1 j:6
 1.r(1 6)temp: 1 2.r(1 6)temp: 1 3.r(1 6)temp: 1Ri:1 j:6 ret : 1 s1 :0 s2 : 4 r : 3 ,c : 4
 3.c(2 3)temp: 1Ci:2 j:3 ret : 1 s1 :0 s2 : 0 r : 3 ,c : 8
 2.r(3 1)temp: 1Ci:5 j:4
 1.c(5 4)temp: 1 2.c(5 4)temp: 1 3.c(5 4)temp: 1Ci:5 j:4 ret : 1 s1 :4 s2 : 0 r : 4 ,c : 8
 3.r(3 1)temp: 1Ri:3 j:1 ret : 2 s1 :0 s2 : 0 r : 8 ,c : 8
Ci:3 j:1
 1.c(3 1)temp: 1 2.c(3 1)temp: 0Ri:1 j:6
 1.r(1 6)temp: 1 2.r(1 6)temp: 1Ri:3 j:4
 1.r(3 4)temp: 1 2.r(3 4)temp: 0Ci:5 j:4
 1.c(5 4)temp: 1 2.c(5 4)temp: 1 3.c(5 4)temp: 1Ci:5 j:4 ret : 1 s1 :4 s2 : 2 r : 4 ,c : 6
 3.r(3 4)temp: 0Ci:3 j:4
 1.c(3 4)temp: 1 2.c(3 4)temp: 0 3.c(3 4)temp: 0 3.r(1 6)temp: 0Ri:3 j:4
 1.r(3 4)temp: 1Ri:1 j:6
 1.r(1 6)temp: 1 2.r(1 6)temp: 1 3.r(1 6)temp: 0 2.r(3 4)temp: 0Ci:5 j:4
 1.c(5 4)temp: 1 2.c(5 4)temp: 1 3.c(5 4)temp: 1Ci:5 j:4 ret : 1 s1 :4 s2 : 2 r : 4 ,c : 6
 3.r(3 4)temp: 0Ci:3 j:4
 1.c(3 4)temp: 1 2.c(3 4)temp: 0Ri:1 j:6
 1.r(1 6)temp: 1 2.r(1 6)temp: 1 3.r(1 6)temp: 0 3.c(3 4)temp: 0 3.c(3 1)temp: 0Ci:3 j:4
 1.c(3 4)temp: 1Ri:3 j:1
 1.r(3 1)temp: 1 2.r(3 1)temp: 0 3.r(3 1)temp: 0 2.c(3 4)temp: 0Ri:1 j:6
 1.r(1 6)temp: 1 2.r(1 6)temp: 1 3.r(1 6)temp: 0 3.c(3 4)temp: 02