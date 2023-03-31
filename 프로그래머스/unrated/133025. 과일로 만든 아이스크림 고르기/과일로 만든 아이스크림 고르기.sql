-- 코드를 입력하세요
SELECT a.flavor from FIRST_HALF as a
LEFT JOIN ICECREAM_INFO AS b
ON a.flavor = b.flavor
where a.total_order > 3000 AND b.INGREDIENT_TYPE = 'fruit_based'
order by a.total_order desc;