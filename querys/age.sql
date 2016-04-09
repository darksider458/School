SELECT SUM(case when DATEDIFF(year,dbo.Employes.Date_of_Birth,GETDATE()) between 18 and 24 then 1 else 0 END ) as[18-24],
	   SUM(case when DATEDIFF(year,dbo.Employes.Date_of_Birth,GETDATE()) between 25 and 36 then 1 else 0 END ) as[25-36],
	   SUM(case when DATEDIFF(year,dbo.Employes.Date_of_Birth,GETDATE()) between 37 and 90 then 1 else 0 END ) as[37-93]
  from Employes

