Action()
{

	web_set_sockets_option("SSL_VERSION", "AUTO");

	/*Possible OAUTH authorization was detected. It is recommended to correlate the authorization parameters.*/

	web_add_auto_header("sec-ch-ua-platform", 
		"\"Windows\"");

	web_add_auto_header("sec-ch-ua", 
		"\"Not A(Brand\";v=\"8\", \"Chromium\";v=\"132\", \"Google Chrome\";v=\"132\"");

	web_add_auto_header("sec-ch-ua-mobile", 
		"?0");

	web_add_header("Sec-Fetch-Site", 
		"none");

	web_add_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_header("Sec-Fetch-Dest", 
		"document");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("opensource-demo.orangehrmlive.com", 
		"URL=https://opensource-demo.orangehrmlive.com/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTTP", 
		LAST);

	web_add_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("Sec-Fetch-Mode", 
		"no-cors");

	web_add_header("Sec-Fetch-Dest", 
		"style");

	web_concurrent_start(NULL);

	web_url("app.css", 
		"URL=https://opensource-demo.orangehrmlive.com/web/dist/css/app.css?v=1721393199309", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=https://opensource-demo.orangehrmlive.com/web/index.php/auth/login", 
		"Snapshot=t2.inf", 
		LAST);

	web_add_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("Sec-Fetch-Mode", 
		"no-cors");

	web_add_header("Sec-Fetch-Dest", 
		"style");

	web_url("chunk-vendors.css", 
		"URL=https://opensource-demo.orangehrmlive.com/web/dist/css/chunk-vendors.css?v=1721393199309", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=https://opensource-demo.orangehrmlive.com/web/index.php/auth/login", 
		"Snapshot=t3.inf", 
		LAST);

	web_add_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("Sec-Fetch-Mode", 
		"no-cors");

	web_add_header("Sec-Fetch-Dest", 
		"script");

	web_url("app.js", 
		"URL=https://opensource-demo.orangehrmlive.com/web/dist/js/app.js?v=1721393199309", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://opensource-demo.orangehrmlive.com/web/index.php/auth/login", 
		"Snapshot=t4.inf", 
		LAST);

	web_add_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("Sec-Fetch-Mode", 
		"no-cors");

	web_add_header("Sec-Fetch-Dest", 
		"script");

	web_url("chunk-vendors.js", 
		"URL=https://opensource-demo.orangehrmlive.com/web/dist/js/chunk-vendors.js?v=1721393199309", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://opensource-demo.orangehrmlive.com/web/index.php/auth/login", 
		"Snapshot=t5.inf", 
		LAST);

	web_add_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("Sec-Fetch-Mode", 
		"no-cors");

	web_add_header("Sec-Fetch-Dest", 
		"image");

	web_url("favicon.ico", 
		"URL=https://opensource-demo.orangehrmlive.com/web/dist/favicon.ico?v=1721393199309", 
		"Resource=1", 
		"RecContentType=image/vnd.microsoft.icon", 
		"Referer=https://opensource-demo.orangehrmlive.com/web/index.php/auth/login", 
		"Snapshot=t6.inf", 
		LAST);

	web_concurrent_end(NULL);

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("Sec-Fetch-Mode", 
		"cors");

	web_add_header("Sec-Fetch-Dest", 
		"empty");

	web_add_header("contentType", 
		"application/json");

	lr_think_time(4);

	web_url("messages", 
		"URL=https://opensource-demo.orangehrmlive.com/web/index.php/core/i18n/messages", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://opensource-demo.orangehrmlive.com/web/index.php/auth/login", 
		"Snapshot=t7.inf", 
		"Mode=HTTP", 
		LAST);

	web_add_header("Sec-Fetch-Mode", 
		"no-cors");

	web_add_header("Sec-Fetch-Dest", 
		"image");

	web_concurrent_start(NULL);

	web_url("ohrm_branding.png", 
		"URL=https://opensource-demo.orangehrmlive.com/web/images/ohrm_branding.png?v=1721393199309", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://opensource-demo.orangehrmlive.com/web/index.php/auth/login", 
		"Snapshot=t8.inf", 
		LAST);

	web_add_header("Sec-Fetch-Mode", 
		"no-cors");

	web_add_header("Sec-Fetch-Dest", 
		"image");

	web_url("blob.svg", 
		"URL=https://opensource-demo.orangehrmlive.com/web/dist/img/blob.svg", 
		"Resource=1", 
		"RecContentType=image/svg+xml", 
		"Referer=https://opensource-demo.orangehrmlive.com/web/dist/css/app.css?v=1721393199309", 
		"Snapshot=t9.inf", 
		LAST);

	web_add_header("Sec-Fetch-Mode", 
		"no-cors");

	web_add_header("Sec-Fetch-Dest", 
		"image");

	web_url("ohrm_logo.png", 
		"URL=https://opensource-demo.orangehrmlive.com/web/images/ohrm_logo.png", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://opensource-demo.orangehrmlive.com/web/index.php/auth/login", 
		"Snapshot=t10.inf", 
		LAST);

	web_add_header("Origin", 
		"https://opensource-demo.orangehrmlive.com");

	web_add_header("Sec-Fetch-Mode", 
		"cors");

	web_add_header("Sec-Fetch-Dest", 
		"font");

	web_url("bootstrap-icons.woff2", 
		"URL=https://opensource-demo.orangehrmlive.com/web/dist/fonts/bootstrap-icons.woff2", 
		"Resource=1", 
		"RecContentType=font/woff2", 
		"Referer=https://opensource-demo.orangehrmlive.com/web/dist/css/chunk-vendors.css?v=1721393199309", 
		"Snapshot=t11.inf", 
		LAST);

	web_add_header("Origin", 
		"https://opensource-demo.orangehrmlive.com");

	web_add_header("Sec-Fetch-Mode", 
		"cors");

	web_add_header("Sec-Fetch-Dest", 
		"font");

	web_url("nunito-sans-v6-latin-ext_latin-regular.woff2", 
		"URL=https://opensource-demo.orangehrmlive.com/web/dist/fonts/nunito-sans-v6-latin-ext_latin-regular.woff2", 
		"Resource=1", 
		"RecContentType=font/woff2", 
		"Referer=https://opensource-demo.orangehrmlive.com/web/dist/css/chunk-vendors.css?v=1721393199309", 
		"Snapshot=t12.inf", 
		LAST);

	web_add_header("Origin", 
		"https://opensource-demo.orangehrmlive.com");

	web_add_header("Sec-Fetch-Mode", 
		"cors");

	web_add_header("Sec-Fetch-Dest", 
		"font");

	web_url("nunito-sans-v6-latin-ext_latin-800.woff2", 
		"URL=https://opensource-demo.orangehrmlive.com/web/dist/fonts/nunito-sans-v6-latin-ext_latin-800.woff2", 
		"Resource=1", 
		"RecContentType=font/woff2", 
		"Referer=https://opensource-demo.orangehrmlive.com/web/dist/css/chunk-vendors.css?v=1721393199309", 
		"Snapshot=t13.inf", 
		LAST);

	web_add_header("Origin", 
		"https://opensource-demo.orangehrmlive.com");

	web_add_header("Sec-Fetch-Mode", 
		"cors");

	web_add_header("Sec-Fetch-Dest", 
		"font");

	web_url("nunito-sans-v6-latin-ext_latin-600.woff2", 
		"URL=https://opensource-demo.orangehrmlive.com/web/dist/fonts/nunito-sans-v6-latin-ext_latin-600.woff2", 
		"Resource=1", 
		"RecContentType=font/woff2", 
		"Referer=https://opensource-demo.orangehrmlive.com/web/dist/css/chunk-vendors.css?v=1721393199309", 
		"Snapshot=t14.inf", 
		LAST);

	web_concurrent_end(NULL);

	lr_start_transaction("Login");

	web_add_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_header("Sec-Fetch-Dest", 
		"document");

	web_add_auto_header("Cache-Control", 
		"max-age=0");

	web_add_header("Origin", 
		"https://opensource-demo.orangehrmlive.com");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(22);

	web_submit_data("validate", 
		"Action=https://opensource-demo.orangehrmlive.com/web/index.php/auth/validate", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://opensource-demo.orangehrmlive.com/web/index.php/auth/login", 
		"Snapshot=t15.inf", 
		"Mode=HTTP", 
		ITEMDATA, 
		"Name=_token", "Value=0b001cf1c7f081b338f117842350b.PJ1Q3SxsU9jwFI-MvEq7dhJxKSrVnZYhKlpATHNBrcM.Y8oEuRQ8IIzdZuTv8wSME2YdZmy7_6UZWxEFP0YO9ZJm6hmXfAsHtoFa-A", ENDITEM, 
		"Name=username", "Value=Admin", ENDITEM, 
		"Name=password", "Value=admin123", ENDITEM, 
		LAST);

	web_add_header("If-None-Match", 
		"\"ZWs3TwZKMQ7IEEFBrjJOSwRM4nXcQgsOPZKkNJnMS5o=\"");

	web_add_auto_header("Sec-Fetch-Dest", 
		"empty");

	web_add_auto_header("Sec-Fetch-Mode", 
		"cors");

	web_add_header("contentType", 
		"application/json");

	web_url("messages_2", 
		"URL=https://opensource-demo.orangehrmlive.com/web/index.php/core/i18n/messages", 
		"Resource=0", 
		"Referer=https://opensource-demo.orangehrmlive.com/web/index.php/dashboard/index", 
		"Snapshot=t16.inf", 
		"Mode=HTTP", 
		LAST);

	web_revert_auto_header("Cache-Control");

	web_add_header("Cache-Control", 
		"no-store, no-cache, must-revalidate, post-check=0, pre-check=0");

	web_url("leaves", 
		"URL=https://opensource-demo.orangehrmlive.com/web/index.php/api/v2/dashboard/employees/leaves?date=2025-02-06", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://opensource-demo.orangehrmlive.com/web/index.php/dashboard/index", 
		"Snapshot=t17.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("feed", 
		"URL=https://opensource-demo.orangehrmlive.com/web/index.php/api/v2/buzz/feed?limit=5&offset=0&sortOrder=DESC&sortField=share.createdAtUtc", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://opensource-demo.orangehrmlive.com/web/index.php/dashboard/index", 
		"Snapshot=t18.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("orange.png", 
		"URL=https://opensource-demo.orangehrmlive.com/web/images/orange.png?v=1721393199309", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://opensource-demo.orangehrmlive.com/web/index.php/dashboard/index", 
		"Snapshot=t19.inf", 
		LAST);

	web_add_auto_header("Cache-Control", 
		"no-store, no-cache, must-revalidate, post-check=0, pre-check=0");

	web_url("action-summary", 
		"URL=https://opensource-demo.orangehrmlive.com/web/index.php/api/v2/dashboard/employees/action-summary", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://opensource-demo.orangehrmlive.com/web/index.php/dashboard/index", 
		"Snapshot=t20.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("time-at-work", 
		"URL=https://opensource-demo.orangehrmlive.com/web/index.php/api/v2/dashboard/employees/time-at-work?timezoneOffset=5.5&currentDate=2025-02-06&currentTime=16:44", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://opensource-demo.orangehrmlive.com/web/index.php/dashboard/index", 
		"Snapshot=t21.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("shortcuts", 
		"URL=https://opensource-demo.orangehrmlive.com/web/index.php/api/v2/dashboard/shortcuts", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://opensource-demo.orangehrmlive.com/web/index.php/dashboard/index", 
		"Snapshot=t22.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("subunit", 
		"URL=https://opensource-demo.orangehrmlive.com/web/index.php/api/v2/dashboard/employees/subunit", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://opensource-demo.orangehrmlive.com/web/index.php/dashboard/index", 
		"Snapshot=t23.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("locations", 
		"URL=https://opensource-demo.orangehrmlive.com/web/index.php/api/v2/dashboard/employees/locations", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://opensource-demo.orangehrmlive.com/web/index.php/dashboard/index", 
		"Snapshot=t24.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("orangehrm-logo.png", 
		"URL=https://opensource-demo.orangehrmlive.com/web/images/orangehrm-logo.png?v=1721393199309", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://opensource-demo.orangehrmlive.com/web/index.php/dashboard/index", 
		"Snapshot=t25.inf", 
		LAST);

	web_revert_auto_header("Cache-Control");

	web_add_auto_header("Origin", 
		"https://opensource-demo.orangehrmlive.com");

	web_custom_request("push", 
		"URL=https://opensource-demo.orangehrmlive.com/web/index.php/events/push", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://opensource-demo.orangehrmlive.com/web/index.php/dashboard/index", 
		"Snapshot=t26.inf", 
		"Mode=HTTP", 
		"EncType=", 
		LAST);

	web_concurrent_start(NULL);

	web_url("7", 
		"URL=https://opensource-demo.orangehrmlive.com/web/index.php/pim/viewPhoto/empNumber/7", 
		"Resource=1", 
		"RecContentType=image/jpeg", 
		"Referer=https://opensource-demo.orangehrmlive.com/web/index.php/dashboard/index", 
		"Snapshot=t27.inf", 
		LAST);

	web_url("dashboard_empty_widget_watermark.png", 
		"URL=https://opensource-demo.orangehrmlive.com/web/images/dashboard_empty_widget_watermark.png", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://opensource-demo.orangehrmlive.com/web/index.php/dashboard/index", 
		"Snapshot=t28.inf", 
		LAST);

	web_url("156", 
		"URL=https://opensource-demo.orangehrmlive.com/web/index.php/pim/viewPhoto/empNumber/156", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://opensource-demo.orangehrmlive.com/web/index.php/dashboard/index", 
		"Snapshot=t29.inf", 
		LAST);

	web_url("nunito-sans-v6-latin-ext_latin-700.woff2", 
		"URL=https://opensource-demo.orangehrmlive.com/web/dist/fonts/nunito-sans-v6-latin-ext_latin-700.woff2", 
		"Resource=1", 
		"RecContentType=font/woff2", 
		"Referer=https://opensource-demo.orangehrmlive.com/web/dist/css/chunk-vendors.css?v=1721393199309", 
		"Snapshot=t30.inf", 
		LAST);

	web_url("nunito-sans-v6-latin-ext_latin-italic.woff2", 
		"URL=https://opensource-demo.orangehrmlive.com/web/dist/fonts/nunito-sans-v6-latin-ext_latin-italic.woff2", 
		"Resource=1", 
		"RecContentType=font/woff2", 
		"Referer=https://opensource-demo.orangehrmlive.com/web/dist/css/chunk-vendors.css?v=1721393199309", 
		"Snapshot=t31.inf", 
		LAST);

	web_url("nunito-sans-v6-latin-ext_latin-300.woff2", 
		"URL=https://opensource-demo.orangehrmlive.com/web/dist/fonts/nunito-sans-v6-latin-ext_latin-300.woff2", 
		"Resource=1", 
		"RecContentType=font/woff2", 
		"Referer=https://opensource-demo.orangehrmlive.com/web/dist/css/chunk-vendors.css?v=1721393199309", 
		"Snapshot=t32.inf", 
		LAST);

	web_concurrent_end(NULL);

	lr_end_transaction("Login",LR_AUTO);

	lr_start_transaction("Click_PIM");

	web_revert_auto_header("Origin");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Dest", 
		"document");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(17);

	web_url("viewPimModule", 
		"URL=https://opensource-demo.orangehrmlive.com/web/index.php/pim/viewPimModule", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://opensource-demo.orangehrmlive.com/web/index.php/dashboard/index", 
		"Snapshot=t33.inf", 
		"Mode=HTTP", 
		LAST);

	web_add_header("If-None-Match", 
		"\"ZWs3TwZKMQ7IEEFBrjJOSwRM4nXcQgsOPZKkNJnMS5o=\"");

	web_add_auto_header("Sec-Fetch-Mode", 
		"cors");

	web_add_auto_header("Sec-Fetch-Dest", 
		"empty");

	web_add_header("Cache-Control", 
		"max-age=0");

	web_add_header("contentType", 
		"application/json");

	web_url("messages_3", 
		"URL=https://opensource-demo.orangehrmlive.com/web/index.php/core/i18n/messages", 
		"Resource=0", 
		"Referer=https://opensource-demo.orangehrmlive.com/web/index.php/pim/viewEmployeeList", 
		"Snapshot=t34.inf", 
		"Mode=HTTP", 
		LAST);

	web_add_auto_header("Sec-Fetch-Mode", 
		"no-cors");

	web_add_auto_header("Sec-Fetch-Dest", 
		"image");

	web_add_header("If-None-Match", 
		"\"P2cce+UXjeBpq9iWKfHdQlYTyOgflCghtVN0ewu0gZM=\"");

	web_url("7_2", 
		"URL=https://opensource-demo.orangehrmlive.com/web/index.php/pim/viewPhoto/empNumber/7", 
		"Resource=0", 
		"Referer=https://opensource-demo.orangehrmlive.com/web/index.php/pim/viewEmployeeList", 
		"Snapshot=t35.inf", 
		"Mode=HTTP", 
		LAST);

	web_add_auto_header("Cache-Control", 
		"no-store, no-cache, must-revalidate, post-check=0, pre-check=0");

	web_add_auto_header("Sec-Fetch-Dest", 
		"empty");

	web_add_auto_header("Sec-Fetch-Mode", 
		"cors");

	web_url("employment-statuses", 
		"URL=https://opensource-demo.orangehrmlive.com/web/index.php/api/v2/admin/employment-statuses?limit=0", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://opensource-demo.orangehrmlive.com/web/index.php/pim/viewEmployeeList", 
		"Snapshot=t36.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("job-titles", 
		"URL=https://opensource-demo.orangehrmlive.com/web/index.php/api/v2/admin/job-titles?limit=0", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://opensource-demo.orangehrmlive.com/web/index.php/pim/viewEmployeeList", 
		"Snapshot=t37.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("subunits", 
		"URL=https://opensource-demo.orangehrmlive.com/web/index.php/api/v2/admin/subunits", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://opensource-demo.orangehrmlive.com/web/index.php/pim/viewEmployeeList", 
		"Snapshot=t38.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("employees", 
		"URL=https://opensource-demo.orangehrmlive.com/web/index.php/api/v2/pim/employees?limit=50&offset=0&model=detailed&includeEmployees=onlyCurrent&sortField=employee.firstName&sortOrder=ASC", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://opensource-demo.orangehrmlive.com/web/index.php/pim/viewEmployeeList", 
		"Snapshot=t39.inf", 
		"Mode=HTTP", 
		LAST);

	lr_end_transaction("Click_PIM",LR_AUTO);

	lr_start_transaction("Click_Add_Employee");

	web_revert_auto_header("Cache-Control");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Dest", 
		"document");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(4);

	web_url("addEmployee", 
		"URL=https://opensource-demo.orangehrmlive.com/web/index.php/pim/addEmployee", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://opensource-demo.orangehrmlive.com/web/index.php/pim/viewEmployeeList", 
		"Snapshot=t40.inf", 
		"Mode=HTTP", 
		LAST);

	web_add_header("If-None-Match", 
		"\"ZWs3TwZKMQ7IEEFBrjJOSwRM4nXcQgsOPZKkNJnMS5o=\"");

	web_add_auto_header("Sec-Fetch-Mode", 
		"cors");

	web_add_auto_header("Sec-Fetch-Dest", 
		"empty");

	web_add_header("Cache-Control", 
		"max-age=0");

	web_add_header("contentType", 
		"application/json");

	web_url("messages_4", 
		"URL=https://opensource-demo.orangehrmlive.com/web/index.php/core/i18n/messages", 
		"Resource=0", 
		"Referer=https://opensource-demo.orangehrmlive.com/web/index.php/pim/addEmployee", 
		"Snapshot=t41.inf", 
		"Mode=HTTP", 
		LAST);

	web_add_auto_header("Sec-Fetch-Mode", 
		"no-cors");

	web_add_auto_header("Sec-Fetch-Dest", 
		"image");

	web_add_header("If-None-Match", 
		"\"P2cce+UXjeBpq9iWKfHdQlYTyOgflCghtVN0ewu0gZM=\"");

	web_url("7_3", 
		"URL=https://opensource-demo.orangehrmlive.com/web/index.php/pim/viewPhoto/empNumber/7", 
		"Resource=0", 
		"Referer=https://opensource-demo.orangehrmlive.com/web/index.php/pim/addEmployee", 
		"Snapshot=t42.inf", 
		"Mode=HTTP", 
		LAST);

	web_add_header("Cache-Control", 
		"no-store, no-cache, must-revalidate, post-check=0, pre-check=0");

	web_add_auto_header("Sec-Fetch-Dest", 
		"empty");

	web_add_auto_header("Sec-Fetch-Mode", 
		"cors");

	web_url("employees_2", 
		"URL=https://opensource-demo.orangehrmlive.com/web/index.php/api/v2/pim/employees", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://opensource-demo.orangehrmlive.com/web/index.php/pim/addEmployee", 
		"Snapshot=t43.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("default-photo.png", 
		"URL=https://opensource-demo.orangehrmlive.com/web/images/default-photo.png", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://opensource-demo.orangehrmlive.com/web/index.php/pim/addEmployee", 
		"Snapshot=t44.inf", 
		LAST);

	lr_end_transaction("Click_Add_Employee",LR_AUTO);

	lr_think_time(9);

	lr_start_transaction("Add_Employee_Details");

	web_url("unique", 
		"URL=https://opensource-demo.orangehrmlive.com/web/index.php/api/v2/core/validation/unique?value=0494&entityName=Employee&attributeName=employeeId", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://opensource-demo.orangehrmlive.com/web/index.php/pim/addEmployee", 
		"Snapshot=t45.inf", 
		"Mode=HTTP", 
		LAST);

	web_add_header("Origin", 
		"https://opensource-demo.orangehrmlive.com");

	web_custom_request("employees_3", 
		"URL=https://opensource-demo.orangehrmlive.com/web/index.php/api/v2/pim/employees", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://opensource-demo.orangehrmlive.com/web/index.php/pim/addEmployee", 
		"Snapshot=t46.inf", 
		"Mode=HTTP", 
		"EncType=application/json", 
		"Body={\"firstName\":\"Jerry\",\"middleName\":\"\",\"lastName\":\"Tom\",\"empPicture\":null,\"employeeId\":\"0494\"}", 
		LAST);

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Dest", 
		"document");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("305", 
		"URL=https://opensource-demo.orangehrmlive.com/web/index.php/pim/viewPersonalDetails/empNumber/305", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://opensource-demo.orangehrmlive.com/web/index.php/pim/addEmployee", 
		"Snapshot=t47.inf", 
		"Mode=HTTP", 
		LAST);

	web_add_header("If-None-Match", 
		"\"ZWs3TwZKMQ7IEEFBrjJOSwRM4nXcQgsOPZKkNJnMS5o=\"");

	web_add_auto_header("Sec-Fetch-Mode", 
		"cors");

	web_add_auto_header("Sec-Fetch-Dest", 
		"empty");

	web_add_header("Cache-Control", 
		"max-age=0");

	web_add_header("contentType", 
		"application/json");

	web_url("messages_5", 
		"URL=https://opensource-demo.orangehrmlive.com/web/index.php/core/i18n/messages", 
		"Resource=0", 
		"Referer=https://opensource-demo.orangehrmlive.com/web/index.php/pim/viewPersonalDetails/empNumber/305", 
		"Snapshot=t48.inf", 
		"Mode=HTTP", 
		LAST);

	web_add_auto_header("Sec-Fetch-Mode", 
		"no-cors");

	web_add_auto_header("Sec-Fetch-Dest", 
		"image");

	web_add_header("If-None-Match", 
		"\"P2cce+UXjeBpq9iWKfHdQlYTyOgflCghtVN0ewu0gZM=\"");

	web_url("7_4", 
		"URL=https://opensource-demo.orangehrmlive.com/web/index.php/pim/viewPhoto/empNumber/7", 
		"Resource=0", 
		"Referer=https://opensource-demo.orangehrmlive.com/web/index.php/pim/viewPersonalDetails/empNumber/305", 
		"Snapshot=t49.inf", 
		"Mode=HTTP", 
		LAST);

	web_add_header("Cache-Control", 
		"no-store, no-cache, must-revalidate, post-check=0, pre-check=0");

	web_add_auto_header("Sec-Fetch-Dest", 
		"empty");

	web_add_auto_header("Sec-Fetch-Mode", 
		"cors");

	web_url("personal-details", 
		"URL=https://opensource-demo.orangehrmlive.com/web/index.php/api/v2/pim/employees/305/personal-details", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://opensource-demo.orangehrmlive.com/web/index.php/pim/viewPersonalDetails/empNumber/305", 
		"Snapshot=t50.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("workweek", 
		"URL=https://opensource-demo.orangehrmlive.com/web/index.php/api/v2/leave/workweek?model=indexed", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://opensource-demo.orangehrmlive.com/web/index.php/pim/viewPersonalDetails/empNumber/305", 
		"Snapshot=t51.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("305_2", 
		"URL=https://opensource-demo.orangehrmlive.com/web/index.php/pim/viewPhoto/empNumber/305", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://opensource-demo.orangehrmlive.com/web/index.php/pim/viewPersonalDetails/empNumber/305", 
		"Snapshot=t52.inf", 
		LAST);

	web_add_header("Cache-Control", 
		"no-store, no-cache, must-revalidate, post-check=0, pre-check=0");

	web_url("custom-fields", 
		"URL=https://opensource-demo.orangehrmlive.com/web/index.php/api/v2/pim/employees/305/custom-fields?screen=personal", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://opensource-demo.orangehrmlive.com/web/index.php/pim/viewPersonalDetails/empNumber/305", 
		"Snapshot=t53.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("305_3", 
		"URL=https://opensource-demo.orangehrmlive.com/web/index.php/api/v2/pim/employees/305", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://opensource-demo.orangehrmlive.com/web/index.php/pim/viewPersonalDetails/empNumber/305", 
		"Snapshot=t54.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("holidays", 
		"URL=https://opensource-demo.orangehrmlive.com/web/index.php/api/v2/leave/holidays?fromDate=2025-01-01&toDate=2025-12-31", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://opensource-demo.orangehrmlive.com/web/index.php/pim/viewPersonalDetails/empNumber/305", 
		"Snapshot=t55.inf", 
		"Mode=HTTP", 
		LAST);

	web_add_header("Cache-Control", 
		"no-store, no-cache, must-revalidate, post-check=0, pre-check=0");

	web_url("attachments", 
		"URL=https://opensource-demo.orangehrmlive.com/web/index.php/api/v2/pim/employees/305/screen/personal/attachments?limit=50&offset=0", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://opensource-demo.orangehrmlive.com/web/index.php/pim/viewPersonalDetails/empNumber/305", 
		"Snapshot=t56.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("employees_4", 
		"URL=https://opensource-demo.orangehrmlive.com/web/index.php/api/v2/pim/employees", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://opensource-demo.orangehrmlive.com/web/index.php/pim/viewPersonalDetails/empNumber/305", 
		"Snapshot=t57.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("workweek_2", 
		"URL=https://opensource-demo.orangehrmlive.com/web/index.php/api/v2/leave/workweek?model=indexed", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://opensource-demo.orangehrmlive.com/web/index.php/pim/viewPersonalDetails/empNumber/305", 
		"Snapshot=t58.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("holidays_2", 
		"URL=https://opensource-demo.orangehrmlive.com/web/index.php/api/v2/leave/holidays?fromDate=2025-01-01&toDate=2025-12-31", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://opensource-demo.orangehrmlive.com/web/index.php/pim/viewPersonalDetails/empNumber/305", 
		"Snapshot=t59.inf", 
		"Mode=HTTP", 
		LAST);

	lr_end_transaction("Add_Employee_Details",LR_AUTO);

	lr_start_transaction("FileUpload");

	web_add_header("Origin", 
		"https://opensource-demo.orangehrmlive.com");

	lr_think_time(34);

	web_custom_request("attachments_2", 
		"URL=https://opensource-demo.orangehrmlive.com/web/index.php/api/v2/pim/employees/305/screen/personal/attachments", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://opensource-demo.orangehrmlive.com/web/index.php/pim/viewPersonalDetails/empNumber/305", 
		"Snapshot=t60.inf", 
		"Mode=HTTP", 
		"EncType=application/json", 
		"Body={\"attachment\":{\"name\":\"World.txt\",\"type\":\"text/plain\",\"size\":12,\"base64\":\"SGVsbG8gV29ybGQh\"},\"description\":\"\"}", 
		LAST);

	web_add_header("Cache-Control", 
		"no-store, no-cache, must-revalidate, post-check=0, pre-check=0");

	web_url("attachments_3", 
		"URL=https://opensource-demo.orangehrmlive.com/web/index.php/api/v2/pim/employees/305/screen/personal/attachments?limit=50&offset=0", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://opensource-demo.orangehrmlive.com/web/index.php/pim/viewPersonalDetails/empNumber/305", 
		"Snapshot=t61.inf", 
		"Mode=HTTP", 
		LAST);

	lr_end_transaction("FileUpload",LR_AUTO);

	lr_start_transaction("Logout");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Dest", 
		"document");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("logout", 
		"URL=https://opensource-demo.orangehrmlive.com/web/index.php/auth/logout", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://opensource-demo.orangehrmlive.com/web/index.php/pim/viewPersonalDetails/empNumber/305", 
		"Snapshot=t62.inf", 
		"Mode=HTTP", 
		LAST);

	web_add_header("Cache-Control", 
		"max-age=0");

	web_add_header("If-None-Match", 
		"\"ZWs3TwZKMQ7IEEFBrjJOSwRM4nXcQgsOPZKkNJnMS5o=\"");

	web_add_auto_header("Sec-Fetch-Dest", 
		"empty");

	web_add_auto_header("Sec-Fetch-Mode", 
		"cors");

	web_add_header("contentType", 
		"application/json");

	web_url("messages_6", 
		"URL=https://opensource-demo.orangehrmlive.com/web/index.php/core/i18n/messages", 
		"Resource=0", 
		"Referer=https://opensource-demo.orangehrmlive.com/web/index.php/auth/login", 
		"Snapshot=t63.inf", 
		"Mode=HTTP", 
		LAST);

	lr_end_transaction("Logout",LR_AUTO);

	return 0;
}