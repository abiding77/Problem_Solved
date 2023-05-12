select ingredient_type,SUM(total_order) as TOTAL_ORDER from first_half join icecream_info where first_half.flavor = icecream_info.flavor
group by INGREDIENT_TYPE;
