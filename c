warning: LF will be replaced by CRLF in src/app/app-routing.module.ts.
The file will have its original line endings in your working directory
warning: LF will be replaced by CRLF in src/app/components/decode/decode.component.html.
The file will have its original line endings in your working directory
warning: LF will be replaced by CRLF in src/app/components/decode/decode.component.ts.
The file will have its original line endings in your working directory
warning: LF will be replaced by CRLF in src/app/components/login/login.component.ts.
The file will have its original line endings in your working directory
warning: LF will be replaced by CRLF in src/app/services/auth.service.ts.
The file will have its original line endings in your working directory
[1mdiff --git a/src/app/app-routing.module.ts b/src/app/app-routing.module.ts[m
[1mindex aa28165..7e4039f 100644[m
[1m--- a/src/app/app-routing.module.ts[m
[1m+++ b/src/app/app-routing.module.ts[m
[36m@@ -2,11 +2,13 @@[m [mimport { NgModule } from '@angular/core';[m
 import { Routes, RouterModule } from '@angular/router';[m
 import { LoginComponent } from './components/login/login.component';[m
 import { DecodeComponent } from './components/decode/decode.component';[m
[32m+[m[32mimport { AuthGuard } from './services/auth.guard';[m
 [m
 const routes: Routes = [[m
   {path:'', redirectTo: 'login', pathMatch:'full'},[m
   {path:'login', component: LoginComponent},[m
   { path:'decode', component: DecodeComponent},[m
[32m+[m[32m  // { path:'decode', canActivate: [AuthGuard], component: DecodeComponent},[m
 ];[m
 [m
 @NgModule({[m
[1mdiff --git a/src/app/components/decode/decode.component.html b/src/app/components/decode/decode.component.html[m
[1mindex 9407553..a8bb384 100644[m
[1m--- a/src/app/components/decode/decode.component.html[m
[1m+++ b/src/app/components/decode/decode.component.html[m
[36m@@ -1 +1,11 @@[m
[31m-<p>decode works!</p>[m
[32m+[m[32m<section style="margin: 5%;">[m
[32m+[m[32m    <div>[m
[32m+[m[32m        <button type="button" class="btn btn-success float-right" (click)="getBatch()">Start Decode</button>[m
[32m+[m[32m    </div>[m
[32m+[m[32m    <div>[m
[32m+[m[32m        <label>Start Key</label>[m
[32m+[m[32m        <input type="text" id="startKey" disabled>[m
[32m+[m[32m        <label>End Key</label>[m
[32m+[m[32m        <input type="text" id="endKey" disabled>[m
[32m+[m[32m    </div>[m
[32m+[m[32m</section>[m
\ No newline at end of file[m
[1mdiff --git a/src/app/components/decode/decode.component.ts b/src/app/components/decode/decode.component.ts[m
[1mindex 7c5b547..4fbea43 100644[m
[1m--- a/src/app/components/decode/decode.component.ts[m
[1m+++ b/src/app/components/decode/decode.component.ts[m
[36m@@ -1,4 +1,5 @@[m
 import { Component, OnInit } from '@angular/core';[m
[32m+[m[32mimport { AuthService }  from 'src/app/services/auth.service';[m
 [m
 @Component({[m
   selector: 'app-decode',[m
[36m@@ -7,9 +8,19 @@[m [mimport { Component, OnInit } from '@angular/core';[m
 })[m
 export class DecodeComponent implements OnInit {[m
 [m
[31m-  constructor() { }[m
[32m+[m[32m  constructor(private auth: AuthService) { }[m
 [m
   ngOnInit() {[m
   }[m
 [m
[32m+[m[32m  getBatch() {[m
[32m+[m[32m    this.auth.LoginApplicatif(localStorage.getItem('JWT'))[m
[32m+[m[32m      .subscribe([m
[32m+[m[32m        res => {[m
[32m+[m[32m          console.log('token',res);[m
[32m+[m[32m          // localStorage.setItem('token', res.token);[m
[32m+[m[32m        },[m
[32m+[m[32m        err => console.error(err)[m
[32m+[m[32m      );[m
[32m+[m[32m  }[m
 }[m
[1mdiff --git a/src/app/components/login/login.component.ts b/src/app/components/login/login.component.ts[m
[1mindex a42c1a9..555d56f 100644[m
[1m--- a/src/app/components/login/login.component.ts[m
[1m+++ b/src/app/components/login/login.component.ts[m
[36m@@ -13,7 +13,21 @@[m [mexport class LoginComponent implements OnInit {[m
   constructor(private auth: AuthService, private router: Router) { }[m
 [m
   loginUserData = {};[m
[31m-[m
[32m+[m[32m  jwtObject = {[m
[32m+[m[32m    Header: {[m
[32m+[m[32m      'alg': "HS256",[m
[32m+[m[32m      'typ': 'JWT'[m
[32m+[m[32m    },[m
[32m+[m[32m    Payload: {[m
[32m+[m[32m      'iss': '',[m
[32m+[m[32m      'sub': '',[m
[32m+[m[32m      'aud':'',[m
[32m+[m[32m      'iat':'',[m
[32m+[m[32m      'exp-after':''[m
[32m+[m[32m    },[m
[32m+[m[32m    Signature : {[m
[32m+[m[32m    }[m
[32m+[m[32m  };[m
   ngOnInit() {[m
   }[m
 [m
[36m@@ -24,8 +38,9 @@[m [mexport class LoginComponent implements OnInit {[m
     this.auth.LoginAuthent(this.loginUserData)[m
       .subscribe([m
         res => {[m
[31m-          console.log('token',res);[m
[31m-          // this.router.navigate(['/solve']);[m
[32m+[m[32m          console.log('JWT',res);[m
[32m+[m[32m          localStorage.setItem('JWT', res);[m
[32m+[m[32m          this.router.navigate(['/decode']);[m
         },[m
         err => console.error(err)[m
       );[m
[1mdiff --git a/src/app/services/auth.service.ts b/src/app/services/auth.service.ts[m
[1mindex 19c2990..5180a9f 100644[m
[1m--- a/src/app/services/auth.service.ts[m
[1m+++ b/src/app/services/auth.service.ts[m
[36m@@ -26,7 +26,7 @@[m [mexport class AuthService {[m
   }[m
 [m
   loggedIn() {[m
[31m-    return !!localStorage.getItem('token');[m
[32m+[m[32m    return !!localStorage.getItem('JWT');[m
   }[m
 [m
   logoutUser() {[m
