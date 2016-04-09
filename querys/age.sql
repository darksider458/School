
SELECT filtred.ranges,sum(filtred.number)  from
(select 
(
case when tab.Age_Difference BETWEEN 18 AND 28 then '18-28'
	 when tab.Age_Difference BETWEEN 29 AND 38 then '29-38'
	 when tab.Age_Difference BETWEEN 39 AND 48 then '39-48'
	 when tab.Age_Difference BETWEEN 49 and 58 then '49-58'
	 when tab.Age_Difference BETWEEN 59 and 68 then '59-68'
	 when tab.Age_Difference BETWEEN 69 and 78 then '69-78'
	 when tab.Age_Difference BETWEEN 79 and 88 then '79-88'
	 when tab.Age_Difference BETWEEN 89 and 98 then '89-98'
	 when tab.Age_Difference >=99 then 'over 99'
	
end
) as ranges
,tab.number from  (select DATEDIFF(year,Customers.Date_of_Birth,GETDATE()) as Age_Difference,COUNT(*) as number from Customers group by DATEDIFF(year,Customers.Date_of_Birth,GETDATE())) as tab
)as filtred
group by filtred.ranges
