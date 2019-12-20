import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';
import { LoginComponent } from './components/login/login.component';
import { DecodeComponent } from './components/decode/decode.component';
import { AuthGuard } from './services/auth.guard';

const routes: Routes = [
  {path:'', redirectTo: 'login', pathMatch:'full'},
  {path:'login', component: LoginComponent},
  { path:'decode', component: DecodeComponent},
  // { path:'decode', canActivate: [AuthGuard], component: DecodeComponent},
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
