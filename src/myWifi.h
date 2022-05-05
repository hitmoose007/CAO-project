

// To send Emails using Gmail on port 465 (SSL), you need to create an app password: https://support.google.com/accounts/answer/185833

#include <Arduino.h>
#include <WiFi.h>

#include <ESP_Mail_Client.h>

#define WIFI_SSID "Kashmir house"
#define WIFI_PASSWORD "Pakistan47"

#define SMTP_HOST "smtp.gmail.com"
#define SMTP_PORT 465

/* The sign in credentials */
#define AUTHOR_EMAIL "jinxx2112@gmail.com"
#define AUTHOR_PASSWORD "Zalalat007"

/* Recipient's email*/
#define RECIPIENT_EMAIL "mustafa1jawad@gmail.com"

unsigned long previousMillis = 0;
unsigned long interval = 30000;

/* The SMTP Session object used for Email sending */
SMTPSession smtp;
SMTP_Message message;

/* Callback function to get the Email sending status */
void smtpCallback(SMTP_Status status);

void setWifi(const String SSID, const String password);
// todo

void enableWifiReconnect();

void setEmailDetails(String authorEmail, String authorPassword, String recipientEmail); // todo

void sendEmail();

/* Callback function to get the Email sending status */
void smtpCallback(SMTP_Status status)
{
    /* Print the current status */
    Serial.println(status.info());

    /* Print the sending result */
    if (status.success())
    {
        Serial.println("----------------");
        ESP_MAIL_PRINTF("Message sent success: %d\n", status.completedCount());
        ESP_MAIL_PRINTF("Message sent failled: %d\n", status.failedCount());
        Serial.println("----------------\n");
        struct tm dt;

        for (size_t i = 0; i < smtp.sendingResult.size(); i++)
        {
            /* Get the result item */
            SMTP_Result result = smtp.sendingResult.getItem(i);
            time_t ts = (time_t)result.timestamp;
            localtime_r(&ts, &dt);

            ESP_MAIL_PRINTF("Message No: %d\n", i + 1);
            ESP_MAIL_PRINTF("Status: %s\n", result.completed ? "success" : "failed");
            ESP_MAIL_PRINTF("Date/Time: %d/%d/%d %d:%d:%d\n", dt.tm_year + 1900, dt.tm_mon + 1, dt.tm_mday, dt.tm_hour, dt.tm_min, dt.tm_sec);
            ESP_MAIL_PRINTF("Recipient: %s\n", result.recipients);
            ESP_MAIL_PRINTF("Subject: %s\n", result.subject);
        }
        Serial.println("----------------\n");
    }
}

void setWifi(const String SSID, const String password)
{
    Serial.print("Connecting to Wifi");
    WiFi.begin(SSID.c_str(), password.c_str());
    while (WiFi.status() != WL_CONNECTED)
    {

        Serial.print(".");
        delay(800);
    }
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    Serial.println();
}

void enableWifiReconnect()
{

    unsigned long currentMillis = millis();

    if ((WiFi.status() != WL_CONNECTED) && (currentMillis - previousMillis >= interval))
    {
        Serial.print(millis());
        Serial.println("Reconnecting to WiFi...");
        WiFi.disconnect();
        WiFi.reconnect();

        if (WiFi.status() == WL_CONNECTED)
        {
            Serial.println("WiFi connected");
        }
        else
        {
            Serial.println("WiFi reconnection failed");
        }

        previousMillis = currentMillis;
    }

} // todo

void setEmailDetails(String authorEmail, String authorPassword, String recipientEmail)
{
    Serial.println();

    smtp.debug(1);

    /* Set the callback function to get the sending results */
    smtp.callback(smtpCallback);

    /* Declare the session config data */
    ESP_Mail_Session session;

    /* Set the session config */
    session.server.host_name = SMTP_HOST;
    session.server.port = SMTP_PORT;
    session.login.email = AUTHOR_EMAIL;
    session.login.password = AUTHOR_PASSWORD;
    session.login.user_domain = "";

    /* Declare the message class */

    /* Set the message headers */
    message.sender.name = "ESP";
    message.sender.email = AUTHOR_EMAIL;
    message.subject = "ESP Test Email";
    message.addRecipient("Sara", RECIPIENT_EMAIL);

    /*Send HTML message*/
    String htmlMsg = "<div style=\"color:#2f4468;\"><h1>Hello World!</h1><p>- Sent from ESP board</p></div>";
    message.html.content = htmlMsg.c_str();
    message.html.content = htmlMsg.c_str();
    message.text.charSet = "us-ascii";
    message.html.transfer_encoding = Content_Transfer_Encoding::enc_7bit;

    /* Connect to server with the session config */
    if (!smtp.connect(&session))
        return;
}
void sendEmail()
{

    /* Start sending Email and close the session */
    if (!MailClient.sendMail(&smtp, &message))
        Serial.println("Error sending Email, " + smtp.errorReason());
}