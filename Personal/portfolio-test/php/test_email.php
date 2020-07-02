<?php
	$to = "atg4691@rit.edu";
	$from = "abc1234@rit.edu";
	$subject = "Web Form";
	$message = "Hello world!";
	$headers = "From: $from" . "\r\n";

	// send the message!
	mail($to,$subject,$message,$headers);
?>