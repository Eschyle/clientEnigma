import { Component, OnInit } from '@angular/core';
import { AuthService }  from 'src/app/services/auth.service';
import { Router } from'@angular/router';
import { from } from 'rxjs';

@Component({
  selector: 'app-login',
  templateUrl: './login.component.html',
  styleUrls: ['./login.component.css']
})
export class LoginComponent implements OnInit {

  constructor(private auth: AuthService, private router: Router) { }

  loginUserData = {};
  jwtObject = {
    Header: {
      'alg': "HS256",
      'typ': 'JWT'
    },
    Payload: {
      'iss': '',
      'sub': '',
      'aud':'',
      'iat':'',
      'exp-after':''
    },
    Signature : {
    }
  };
  ngOnInit() {
  }

  loginUser() {
    //base64 encode du ot de passe
    this.loginUserData.password = btoa(this.loginUserData.password); 
    console.log(this.loginUserData);
    this.auth.LoginAuthent(this.loginUserData)
      .subscribe(
        res => {
          console.log('JWT',res);
          localStorage.setItem('JWT', res);
          this.router.navigate(['/decode']);
        },
        err => console.error(err)
      );
  }
}
