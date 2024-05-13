# Write your MySQL query statement 
SELECT  w1.id
    FROM Weather w1
    INNER JOIN Weather w2
    WHERE DATEDIFF(w1.recordDate,w2.recordDate)=1
    AND w1.temperature>w2.temperature;

#to check the diffrence between previous and present use join and 