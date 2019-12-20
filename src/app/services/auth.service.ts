import { Injectable } from '@angular/core';
import { HttpClient, HttpClientModule } from '@angular/common/http';
// import { Http } from '@angular/http';
import { Router } from '@angular/router';
import { from } from 'rxjs';

@Injectable({
  providedIn: 'root'
})
export class AuthService {

  //ICI LES ADRESSES DES SERVEURs D'AUTHENTIFICATION ET APPLICATIF
  //pour le serveur d'authent il n'y a qu'une seule route donc la route compète est rentré
  private authentLoginUrl = 'http://localhost:8095/auth/login';
  //pour le serveur applicatif il y a plusieurs routes donc on ne renseigne que la base
  private applicatifLoginUrl = 'http://localhost:8098';

  constructor(private http: HttpClient, private router: Router) { }

  LoginAuthent(user: any) {
    return this.http.get<any>(this.authentLoginUrl, user);
  }

  LoginApplicatif(user: any) {
    return this.http.post<any>(this.applicatifLoginUrl, user);
  }

  loggedIn() {
    return !!localStorage.getItem('JWT');
  }

  logoutUser() {
    localStorage.removeItem('token');
    this.router.navigate(['/login']);
  }
  
  getToken() {
    return localStorage.getItem('token');
  }
}
