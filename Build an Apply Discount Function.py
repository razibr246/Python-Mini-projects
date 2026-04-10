def apply_discount(price, discount):
    # Check if price is a number
    if not isinstance(price, (int, float)):
        return "The price should be a number"
    
    # Check if discount is a number
    if not isinstance(discount, (int, float)):
        return "The discount should be a number"
    
    # Check if price is greater than 0
    if price <= 0:
        return "The price should be greater than 0"
    
    # Check if discount is between 0 and 100
    if discount < 0 or discount > 100:
        return "The discount should be between 0 and 100"
    
    # Calculate final price
    discount_amount = price * (discount / 100)
    final_price = price - discount_amount
    
    return final_price
