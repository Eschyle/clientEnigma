import { Component, OnInit } from '@angular/core';
import { AuthService }  from 'src/app/services/auth.service';

@Component({
  selector: 'app-decode',
  templateUrl: './decode.component.html',
  styleUrls: ['./decode.component.css']
})
export class DecodeComponent implements OnInit {

  constructor(private auth: AuthService) { }

  ngOnInit() {
  }

  getBatch() {
    this.auth.LoginApplicatif(localStorage.getItem('JWT'))
      .subscribe(
        res => {
          console.log('token',res);
          // localStorage.setItem('token', res.token);
        },
        err => console.error(err)
      );
  }
}
