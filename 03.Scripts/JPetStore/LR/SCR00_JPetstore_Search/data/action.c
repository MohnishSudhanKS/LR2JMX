Action()
{

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_auto_header("Accept-Language", 
		"en-US,en;q=0.9");

	web_url("petstore.octoperf.com", 
		"URL=https://petstore.octoperf.com/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	lr_start_transaction("Enter_Store");

	web_link("Enter the Store", 
		"Text=Enter the Store", 
		"Snapshot=t6.inf", 
		LAST);

	lr_end_transaction("Enter_Store",LR_AUTO);

	lr_think_time(6);

	lr_start_transaction("Signin");

	web_link("Sign In", 
		"Text=Sign In", 
		"Snapshot=t7.inf", 
		LAST);

	web_submit_form("Account.action", 
		"Snapshot=t8.inf", 
		ITEMDATA, 
		"Name=username", "Value=j2ee", ENDITEM, 
		"Name=password", "Value=j2ee", ENDITEM, 
		"Name=signon", "Value=Login", ENDITEM, 
		LAST);

	lr_end_transaction("Signin",LR_AUTO);

	lr_think_time(21);

	lr_start_transaction("search");

	web_submit_form("Catalog.action", 
		"Snapshot=t9.inf", 
		ITEMDATA, 
		"Name=keyword", "Value=fish", ENDITEM, 
		"Name=searchProducts", "Value=Search", ENDITEM, 
		LAST);

	lr_end_transaction("search",LR_AUTO);

	lr_think_time(17);

	lr_start_transaction("select_fish");

	web_link("Fresh Water fish from China", 
		"Text=Fresh Water fish from China", 
		"Snapshot=t10.inf", 
		LAST);

	lr_end_transaction("select_fish",LR_AUTO);

	lr_think_time(18);

	lr_start_transaction("add_to_cart");

	web_link("Add to Cart", 
		"Text=Add to Cart", 
		"Ordinal=1", 
		"Snapshot=t11.inf", 
		LAST);

	lr_end_transaction("add_to_cart",LR_AUTO);

	lr_start_transaction("logout");

	web_link("Sign Out", 
		"Text=Sign Out", 
		"Snapshot=t12.inf", 
		LAST);

	lr_end_transaction("logout",LR_AUTO);

	return 0;
}